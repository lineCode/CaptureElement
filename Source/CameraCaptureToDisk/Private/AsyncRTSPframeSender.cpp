#include "AsyncRTSPframeSender.h"

AME::AsyncRTSPframeSender::AsyncRTSPframeSender()
{
    bRecord.store(false);
    Thread = FRunnableThread::Create(this, TEXT("AsyncRTSPframeSender"));
}

AME::AsyncRTSPframeSender::~AsyncRTSPframeSender()
{
    if (Thread)
    {
        // Kill() is a blocking call, it waits for the thread to finish (call Stop() func).
        // Hopefully that doesn't take too long
        Thread->Kill();
        Thread->WaitForCompletion();
        delete Thread;
    }
}

void AME::AsyncRTSPframeSender::InitVars(std::shared_ptr<xop::RtspServer> server, xop::MediaSessionId& session_id)
{
    Server = server; 
    Session_id = session_id;

    AME::IAsync::Init();

    memset(&param, 0, sizeof(SEncParamBase));
    param.iUsageType = CAMERA_VIDEO_REAL_TIME;
    param.fMaxFrameRate = 40;
    param.iPicWidth = FrameWidth;
    param.iPicHeight = FrameHeight;
    param.iTargetBitrate = 1000000;

    memset(&info, 0, sizeof(SFrameBSInfo));
    memset(&pic, 0, sizeof(SSourcePicture));
    pic.iPicWidth = FrameWidth;
    pic.iPicHeight = FrameHeight;
    pic.iColorFormat = videoFormatI420;
}

bool AME::AsyncRTSPframeSender::Init()
{
    return true;
}

void AME::AsyncRTSPframeSender::Stop()
{
    bRecord.store(false);
    AME::IAsync::Stop();
}

uint32 AME::AsyncRTSPframeSender::Run()
{
    std::unique_lock<std::mutex> lock(mutex);
    TArray64<uint8> img;

    while (!bStop.load())
    {
        if (bRecord.load())
        {
            if (!ImageQueue.IsEmpty())
            {
                ImageQueue.Peek(img);
                RGBAtoRGB(img, rawImage);
                ImageQueue.Pop();
            }

            rv = WelsCreateSVCEncoder(&encoder_);
            encoder_->Initialize(&param);
            
            cv::cvtColor(rawImage, imageYuv, cv::COLOR_BGR2YUV);
            cv::split(imageYuv, imageYuvCh);
            cv::resize(imageYuv, imageYuvMini, cv::Size(FrameWidth / 2, FrameHeight / 2));
            cv::split(imageYuvMini, imageYuvMiniCh);
            pic.iStride[0] = imageYuvCh[0].step;
            pic.iStride[1] = imageYuvMiniCh[1].step;
            pic.iStride[2] = imageYuvMiniCh[2].step;
            pic.pData[0] = imageYuvCh[0].data;
            pic.pData[1] = imageYuvMiniCh[1].data;
            pic.pData[2] = imageYuvMiniCh[2].data;

            rv = encoder_->EncodeFrame(&pic, &info);
            if (rv != cmResultSuccess)
            {
                UE_LOG(LogTemp, Error, TEXT("rv failed"));
                continue;
            }

            if (info.eFrameType != videoFrameTypeSkip)
            {
                //output bitstream
                for (int iLayer = 0; iLayer < info.iLayerNum; iLayer++)
                {
                    SLayerBSInfo* pLayerBsInfo = &info.sLayerInfo[iLayer];
                    int iLayerSize = 0;
                    int iNalIdx = pLayerBsInfo->iNalCount - 1;

                    do
                    {
                        iLayerSize += pLayerBsInfo->pNalLengthInByte[iNalIdx];
                        --iNalIdx;
                    } while (iNalIdx >= 0);

                    uint8_t* outBuf = pLayerBsInfo->pBsBuf;
                    xop::AVFrame videoFrame = { 0 };
                    videoFrame.type = 0;
                    videoFrame.size = iLayerSize;
                    videoFrame.timestamp = xop::H264Source::GetTimestamp();
                    videoFrame.buffer.reset(new uint8_t[videoFrame.size]);
                    memcpy(videoFrame.buffer.get(), outBuf, videoFrame.size);

                    if (!bStop.load())
                        Server.get()->PushFrame(Session_id, xop::channel_0, videoFrame);
                }
            }
            
            if (encoder_)
            {
                encoder_->Uninitialize();
                WelsDestroySVCEncoder(encoder_);
            }
        }
        else
        {
            ImageQueue.Empty();
           
            cv.wait(lock, [this] {return bStop.load() || bRecord.load(); });
        }
    }

    return 0;
}
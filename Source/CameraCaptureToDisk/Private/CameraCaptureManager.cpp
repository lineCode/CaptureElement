// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraCaptureManager.h"

#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Engine/SceneCapture2D.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Kismet/GameplayStatics.h"
#include "ShowFlags.h"
#include "Materials/Material.h"
#include "RHICommandList.h"

#include "ImageWrapper/Public/IImageWrapper.h"
#include "ImageWrapper/Public/IImageWrapperModule.h"

#include "ImageUtils.h"
#include "Modules/ModuleManager.h"
#include "Misc/FileHelper.h"

#include  <filesystem>

// Sets default values
UCameraCaptureManager::UCameraCaptureManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.TickInterval = 0.015;
}

UCameraCaptureManager::~UCameraCaptureManager()
{
}

void UCameraCaptureManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (ScreenShotmaker.Get())
    {
        ScreenShotmaker.Get()->bStop = true;
    }

    if (RTPSmaker.Get())
    {
        RTPSmaker.Get()->bStop = true;
    }

    if (Videomaker.Get())
    {
        Videomaker.Get()->bStop = true;
    }

    Super::EndPlay(EndPlayReason);
}

// Called when the game starts or when spawned
void UCameraCaptureManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UCameraCaptureManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!CaptureComponent)
    {
    	UE_LOG(LogTemp, Error, TEXT("No CaptureComponent set!"));
        return;
    }
    
    // READ UINT8 IMAGE
	// Read pixels once RenderFence is completed
   
    if(!ScreenShotRequestQueue.IsEmpty())
    {
        // Peek the next RenderRequest from queue
        FRenderRequestStruct* nextRenderRequest = nullptr;
        ScreenShotRequestQueue.Peek(nextRenderRequest);

        if(nextRenderRequest)
        { //nullptr check
            if(nextRenderRequest->RenderFence.IsFenceComplete())
            { // Check if rendering is done, indicated by RenderFence
                // Load the image wrapper module 
                IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));

                // Prepare data to be written to disk
                static TSharedPtr<IImageWrapper> imageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG); //EImageFormat::PNG //EImageFormat::JPEG
                imageWrapper->SetRaw(nextRenderRequest->Image.GetData(), nextRenderRequest->Image.GetAllocatedSize(), FrameWidth, FrameHeight, ERGBFormat::BGRA, 8);
                //const TArray64<uint8>& ImgData = imageWrapper->GetCompressed(5);

                TArray64<uint8> ImgData2;
                imageWrapper->GetRaw(ERGBFormat::BGRA, 8, ImgData2);

                if (ScreenShotmaker.Get())
                    ScreenShotmaker.Get()->ImageQueue.push(ImgData2);

                // Delete the first element from RenderQueue
                ScreenShotRequestQueue.Pop();
                delete nextRenderRequest;
            }
        }
    }

    if ((bMakeRTPS && RTPSmaker.Get()) || (bVideoRecord && Videomaker.Get()))
    {
        if (!RTPSRequestQueue.IsEmpty())
        {
            // Peek the next RenderRequest from queue
            FRenderRequestStruct* nextRenderRequest = nullptr;
            RTPSRequestQueue.Peek(nextRenderRequest);

            if (nextRenderRequest)
            { //nullptr check
                if (nextRenderRequest->RenderFence.IsFenceComplete())
                { // Check if rendering is done, indicated by RenderFence
                    // Load the image wrapper module 
                    IImageWrapperModule& RTPSImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));

                    // Prepare data to be written to disk
                    static TSharedPtr<IImageWrapper> RTPSimageWrapper = RTPSImageWrapperModule.CreateImageWrapper(EImageFormat::PNG); //EImageFormat::PNG //EImageFormat::JPEG
                    RTPSimageWrapper->SetRaw(nextRenderRequest->Image.GetData(), nextRenderRequest->Image.GetAllocatedSize(), FrameWidth, FrameHeight, ERGBFormat::BGRA, 8);
                    //const TArray64<uint8>& ImgData = imageWrapper->GetCompressed(5);

                    TArray64<uint8> ImgData2;
                    RTPSimageWrapper->GetRaw(ERGBFormat::BGRA, 8, ImgData2);

                    if (FrameSender && bMakeRTPS)
                        FrameSender->ImageQueue.push(ImgData2);

                    if (Videomaker.Get() && bVideoRecord)
                        Videomaker.Get()->ImageQueue.push(ImgData2);

                    // Delete the first element from RenderQueue
                    RTPSRequestQueue.Pop();
                    delete nextRenderRequest;
                }
            }
        }
        MakeRTPSshot();
    }
}

void UCameraCaptureManager::StartVideoRecord(bool bState)
{
    bVideoRecord = bState;

    if (Videomaker.Get())
    {
        Videomaker.Get()->bRecord = bState;

        if (bState)
            Videomaker.Get()->InitRecorder();
    }
}

void UCameraCaptureManager::StartRTPS(bool bState)
{
    bMakeRTPS = bState;

    if (FrameSender)
        FrameSender->bRecord = bState;
}

void UCameraCaptureManager::SetupCaptureComponent(USceneCaptureComponent2D* captureComponent)
{
    CaptureComponent = captureComponent;
    FrameWidth = 1280;
    FrameHeight = 720;

    if(!IsValid(CaptureComponent))
    {
        UE_LOG(LogTemp, Error, TEXT("SetupCaptureComponent: CaptureComponent is not valid!"));
        return;
    }

    // Create RenderTargets
    renderTarget2D = NewObject<UTextureRenderTarget2D>();
    
    renderTarget2D->RenderTargetFormat = ETextureRenderTargetFormat::RTF_RGBA8; //8-bit color format
    renderTarget2D->InitCustomFormat(FrameWidth, FrameHeight, PF_B8G8R8A8, false); // PF... disables HDR, which is most important since HDR gives gigantic overhead, and is not needed!
    UE_LOG(LogTemp, Warning, TEXT("Set Render Format for Color-Like-Captures"));
    
    renderTarget2D->bGPUSharedFlag = true; // demand buffer on GPU

    // Assign RenderTarget
    CaptureComponent->TextureTarget = renderTarget2D;
    // Set Camera Properties
    CaptureComponent->CaptureSource = ESceneCaptureSource::SCS_FinalColorHDR;
    // CaptureComponent->GetCaptureComponent2D()->TextureTarget->TargetGamma = GEngine->GetDisplayGamma();
    //CaptureComponent->GetCaptureComponent2D()->ShowFlags.SetTemporalAA(true);
    
    UE_LOG(LogTemp, Warning, TEXT("Initialized RenderTarget!"));

    renderTarget2D->UpdateResourceImmediate();

    FString test = FPaths::ProjectSavedDir() + "capture";
    FPaths::MakeStandardFilename(test);
    std::filesystem::create_directory(TCHAR_TO_UTF8(*test));

    if (!ScreenShotmaker.Get())
        ScreenShotmaker = MakeUnique<AsyncSaveScreenShotmaker>(this);

    if (!RTPSmaker.Get())
        RTPSmaker = MakeUnique<AsyncRTSPserver>(this);

    if (!Videomaker.Get())
        Videomaker = MakeUnique<AsyncVideomaker>(this);
}

void UCameraCaptureManager::MakeRTPSshot()
{
    if (!IsValid(CaptureComponent))
    {
        UE_LOG(LogTemp, Error, TEXT("CaptureColorNonBlocking: CaptureComponent was not valid!"));
        return;
    }

    // Get RenderConterxt
    FTextureRenderTargetResource* renderTargetResource = CaptureComponent->TextureTarget->GameThread_GetRenderTargetResource();

    struct FReadSurfaceContext
    {
        FRenderTarget* SrcRenderTarget;
        TArray<FColor>* OutData;
        FIntRect Rect;
        FReadSurfaceDataFlags Flags;
    };

    // Init new RenderRequest
    FRenderRequestStruct* renderRequest = new FRenderRequestStruct();


    // Setup GPU command
    FReadSurfaceContext readSurfaceContext = {
        renderTargetResource,
        &(renderRequest->Image),
        FIntRect(0,0,renderTargetResource->GetSizeXY().X, renderTargetResource->GetSizeXY().Y),
        FReadSurfaceDataFlags(RCM_UNorm, CubeFace_MAX)
    };

    ENQUEUE_RENDER_COMMAND(SceneDrawCompletion)(
        [readSurfaceContext](FRHICommandListImmediate& RHICmdList)
        {
            RHICmdList.ReadSurfaceData(
                readSurfaceContext.SrcRenderTarget->GetRenderTargetTexture(),
                readSurfaceContext.Rect,
                *readSurfaceContext.OutData,
                readSurfaceContext.Flags
            );
        });

    // Notifiy new task in RenderQueue
    RTPSRequestQueue.Enqueue(renderRequest);

    // Set RenderCommandFence
    renderRequest->RenderFence.BeginFence();
}


void UCameraCaptureManager::MakeScreenShot()
{
    if(!IsValid(CaptureComponent))
    {
        UE_LOG(LogTemp, Error, TEXT("CaptureColorNonBlocking: CaptureComponent was not valid!"));
        return;
    }
    UE_LOG(LogTemp, Warning, TEXT("Entering: CaptureNonBlocking"));

    // Get RenderConterxt
    FTextureRenderTargetResource* renderTargetResource = CaptureComponent->TextureTarget->GameThread_GetRenderTargetResource();
    UE_LOG(LogTemp, Warning, TEXT("Got display gamma"));
    struct FReadSurfaceContext
    {
        FRenderTarget* SrcRenderTarget;
        TArray<FColor>* OutData;
        FIntRect Rect;
        FReadSurfaceDataFlags Flags;
    };
    UE_LOG(LogTemp, Warning, TEXT("Inited ReadSurfaceContext"));
    // Init new RenderRequest
    FRenderRequestStruct* renderRequest = new FRenderRequestStruct();
    UE_LOG(LogTemp, Warning, TEXT("inited renderrequest"));

    // Setup GPU command
    FReadSurfaceContext readSurfaceContext = {
        renderTargetResource,
        &(renderRequest->Image),
        FIntRect(0,0,renderTargetResource->GetSizeXY().X, renderTargetResource->GetSizeXY().Y),
        FReadSurfaceDataFlags(RCM_UNorm, CubeFace_MAX)
    };
    UE_LOG(LogTemp, Warning, TEXT("GPU Command complete"));

    ENQUEUE_RENDER_COMMAND(SceneDrawCompletion)(
    [readSurfaceContext](FRHICommandListImmediate& RHICmdList)
        {
        RHICmdList.ReadSurfaceData(
            readSurfaceContext.SrcRenderTarget->GetRenderTargetTexture(),
            readSurfaceContext.Rect,
            *readSurfaceContext.OutData,
            readSurfaceContext.Flags
        );
    });

    // Notifiy new task in RenderQueue
    ScreenShotRequestQueue.Enqueue(renderRequest);

    // Set RenderCommandFence
    renderRequest->RenderFence.BeginFence();
}

/*
*******************************************************************
*/

AsyncSaveScreenShotmaker::AsyncSaveScreenShotmaker(UCameraCaptureManager* manager)
{
    Manager = manager;
    Thread = FRunnableThread::Create(this, TEXT("AsyncSaveScreenShotmaker"));
}

AsyncSaveScreenShotmaker::~AsyncSaveScreenShotmaker()
{
    if (Thread)
    {
        bStop = true;
        // Kill() is a blocking call, it waits for the thread to finish.
        // Hopefully that doesn't take too long
        Thread->Kill();
        delete Thread;
    }
}

FString AsyncSaveScreenShotmaker::ToStringWithLeadingZeros(int32 Integer, int32 MaxDigits)
{
    FString result = FString::FromInt(Integer);
    int32 stringSize = result.Len();
    int32 stringDelta = MaxDigits - stringSize;

    if(stringDelta < 0)
    {
        UE_LOG(LogTemp, Error, TEXT("MaxDigits of ImageCounter Overflow!"));
        return result;
    }
    //FIXME: Smarter function for this..
    FString leadingZeros = "";
    for(size_t i=0;i<stringDelta;i++)
    {
        leadingZeros += "0";
    }
    result = leadingZeros + result;

    return result;
}

bool AsyncSaveScreenShotmaker::Init()
{
    return true;
}

void AsyncSaveScreenShotmaker::Stop()
{
}

uint32 AsyncSaveScreenShotmaker::Run()
{
    cv::Mat wrappedImage(720, 1280, CV_8UC(4));

    while (!bStop)
    {
        if(!ImageQueue.empty())
        {
            ImageCopy = ImageQueue.front();
            ImageQueue.pop();
            //Generate image name
            FileName = FPaths::ProjectSavedDir() + "capture/img" + "_" + ToStringWithLeadingZeros(ImgCounter, NumDigits);
            FileName += ".png"; // Add file ending

            int FrameWidth = 1280;
            int FrameHeight = 720;

            memcpy(wrappedImage.data, ImageCopy.GetData(), ImageCopy.Num());
            cv::split(wrappedImage, channels);
            vectorToCombine.push_back(channels[0]);
            vectorToCombine.push_back(channels[1]);
            vectorToCombine.push_back(channels[2]);

            cv::merge(vectorToCombine, rawImage);
            cv::imwrite(TCHAR_TO_ANSI(*FileName), rawImage);

            vectorToCombine.clear();
            ImgCounter++;
        }
    }
    return 0;
}

AsyncRTSPserver::AsyncRTSPserver(UCameraCaptureManager* manager)
{
    Manager = manager;
    Thread = FRunnableThread::Create(this, TEXT("AsyncRTPSmaker"));
}

AsyncRTSPserver::~AsyncRTSPserver()
{
    if (Thread)
    {
        bStop = true;
        // Kill() is a blocking call, it waits for the thread to finish.
        // Hopefully that doesn't take too long
        Thread->Kill();
        delete Thread;
    }
}

bool AsyncRTSPserver::Init()
{
    std::string suffix = "live";
    std::string ip = "127.0.0.1";
    std::string port = "554";
    std::string rtsp_url = "rtsp://" + ip + ":" + port + "/" + suffix;

    event_loop = std::make_shared<xop::EventLoop>();
    server = xop::RtspServer::Create(event_loop.get());

    if (!server->Start("0.0.0.0", atoi(port.c_str()))) 
    {
        FString str(port.c_str());
        UE_LOG(LogTemp, Error, TEXT("RTSP Server listen on %s failed."), *str);
        return 0;
    }

    server->SetAuthConfig("-_-", "admin", "12345");

    session = xop::MediaSession::CreateNew("live");
    session->AddSource(xop::channel_0, xop::H264Source::CreateNew());
    session->AddNotifyConnectedCallback([](xop::MediaSessionId sessionId, std::string peer_ip, uint16_t peer_port) 
        {
            FString str(peer_ip.c_str());
            UE_LOG(LogTemp, Error, TEXT("RTSP client connect, ip=%s, port=%d"), *str, peer_port);
        });

    session->AddNotifyDisconnectedCallback([](xop::MediaSessionId sessionId, std::string peer_ip, uint16_t peer_port) 
        {
            FString str(peer_ip.c_str());
            UE_LOG(LogTemp, Error, TEXT("RTSP client disconnect, ip=%s, port=%d"), *str, peer_port);
        });

    session_id = server->AddSession(session);

    FrameSender = MakeUnique<AsyncRTSPframeSender>(server, session_id);
    Manager->FrameSender = FrameSender.Get();

    return true;
}

void AsyncRTSPserver::Stop()
{
    bStop = true;
}

uint32 AsyncRTSPserver::Run()
{
    while (!bStop)
    {
    }
    return 0;
}

AsyncRTSPframeSender::AsyncRTSPframeSender(std::shared_ptr<xop::RtspServer> server, xop::MediaSessionId session_id)
{
    Server = server;
    Session_id = session_id;

    Thread = FRunnableThread::Create(this, TEXT("AsyncRTSPframeSender"));
}

AsyncRTSPframeSender::~AsyncRTSPframeSender()
{
    if (Thread)
    {
        bStop = true;
        // Kill() is a blocking call, it waits for the thread to finish.
        // Hopefully that doesn't take too long
        Thread->Kill();
        delete Thread;
    }
}

bool AsyncRTSPframeSender::Init()
{
    wrappedImage = cv::Mat(FrameHeight, FrameWidth, CV_8UC(4), cv::Scalar(0));
    rawImage = cv::Mat(FrameHeight, FrameWidth, CV_8UC(3), cv::Scalar(0));

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

    return true;
}

void AsyncRTSPframeSender::Stop()
{
    bStop = true;
    bRecord = false;
}

uint32 AsyncRTSPframeSender::Run()
{
    while (!bStop)
    {
        if (bRecord)
        {
            if (!ImageQueue.empty())
            {
                ImageCopy = ImageQueue.front();
                ImageQueue.pop();

                memcpy(wrappedImage.data, ImageCopy.GetData(), ImageCopy.Num());
                cv::split(wrappedImage, channels);
                vectorToCombine.push_back(channels[0]);
                vectorToCombine.push_back(channels[1]);
                vectorToCombine.push_back(channels[2]);
                cv::merge(vectorToCombine, rawImage);
                vectorToCombine.clear();
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
            }
            
            if (info.eFrameType != videoFrameTypeSkip /*&& cbk != nullptr*/)
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

                    if (!bStop)
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
            if (!ImageQueue.empty())
            {
                decltype(ImageQueue) empty{};
                std::swap(ImageQueue, empty);
            }
        }
    }

    return 0;
}

AsyncVideomaker::AsyncVideomaker(UCameraCaptureManager* manager)
{
    Manager = manager;
    Thread = FRunnableThread::Create(this, TEXT("AsyncVideomaker"));
}

AsyncVideomaker::~AsyncVideomaker()
{
    if (Thread)
    {
        bStop = true;
        // Kill() is a blocking call, it waits for the thread to finish.
        // Hopefully that doesn't take too long
        Thread->Kill();
        delete Thread;
    }
}

void AsyncVideomaker::InitRecorder()
{
    int codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
    double fps = 30.0;
    FString filename = FPaths::ProjectSavedDir() + "capture/";

    filename.Append(FDateTime::Now().ToString());
    filename.Append(".avi");
    FPaths::MakeStandardFilename(filename);
    bool status = video_.open(std::string(TCHAR_TO_UTF8(*filename)), codec, fps, cv::Size(1280, 720));
    UE_LOG(LogTemp, Warning, TEXT("video file path: %s"), *filename);
}

bool AsyncVideomaker::Init()
{
    rawImage = cv::Mat(FrameHeight, FrameWidth, CV_8UC(3), cv::Scalar(0));
    wrappedImage = cv::Mat(FrameHeight, FrameWidth, CV_8UC(4), cv::Scalar(0));
    return true;
}

void AsyncVideomaker::Stop()
{
    bStop = true;
    bRecord = false;
}

uint32 AsyncVideomaker::Run()
{
    while (!bStop)
    {
        if (bRecord)
        {
            if (!ImageQueue.empty() && video_.isOpened())
            {
                ImageCopy = ImageQueue.front();
                ImageQueue.pop();

                memcpy(wrappedImage.data, ImageCopy.GetData(), ImageCopy.Num());
                cv::split(wrappedImage, channels);
                vectorToCombine.push_back(channels[0]);
                vectorToCombine.push_back(channels[1]);
                vectorToCombine.push_back(channels[2]);
                cv::merge(vectorToCombine, rawImage);

                video_.write(rawImage);
                vectorToCombine.clear();
            }
        }
        else
        {
            if (video_.isOpened())
                video_.release();

            if (!ImageQueue.empty())
            {
                decltype(ImageQueue) empty{};
                std::swap(ImageQueue, empty);
            }
        }
    }
    return 0;
}



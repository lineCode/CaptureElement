#pragma once

#include "AsyncIO.h"
#include <codec_api.h>
#include "xop/RtspServer.h"

namespace AME
{
    class AsyncRTSPframeSender;
}

class AME::AsyncRTSPframeSender : public FRunnable
{
public:
    explicit AsyncRTSPframeSender(std::shared_ptr<xop::RtspServer> server, xop::MediaSessionId session_id);
    virtual ~AsyncRTSPframeSender() override;
    mutable std::queue<TArray64<uint8>> ImageQueue{};

public:
    mutable bool bStop = false;
    mutable bool bRecord = false;

    virtual bool Init() override; // Do your setup here, allocate memory, ect.
    virtual uint32 Run() override; // Main data processing happens here
    virtual void Stop() override; // Clean up any memory you allocated here

protected:
    std::shared_ptr<xop::RtspServer> Server;

    xop::MediaSessionId Session_id;
    FRunnableThread* Thread;

    ISVCEncoder* encoder_ = nullptr;
    SFrameBSInfo info;
    SSourcePicture pic;
    SEncParamBase param;

    int rv;
    std::vector<cv::Mat> vectorToCombine;
    cv::Mat channels[4];
    cv::Mat rawImage;
    cv::Mat imageYuv, imageYuvMini;
    cv::Mat imageYuvCh[3], imageYuvMiniCh[3];

    TArray64<uint8> ImageCopy{};
    cv::Mat wrappedImage;

    int FrameWidth = 1280;
    int FrameHeight = 720;
};
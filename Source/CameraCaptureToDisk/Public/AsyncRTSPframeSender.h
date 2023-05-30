#pragma once

#include "AsyncIO.h"
#include <codec_api.h>
#include "xop/RtspServer.h"

namespace AME
{
    class AsyncRTSPframeSender;
}

class AME::AsyncRTSPframeSender : public AME::IAsync
{
public:
    explicit AsyncRTSPframeSender(std::shared_ptr<xop::RtspServer> server, xop::MediaSessionId session_id, UCameraCaptureManager* manager);
    virtual ~AsyncRTSPframeSender() override = default;

public:
    virtual bool Init() override; // Do your setup here, allocate memory, ect.
    virtual uint32 Run() override; // Main data processing happens here
    virtual void Stop() override; // Clean up any memory you allocated here

    volatile bool bRecord = false;

protected:
    std::shared_ptr<xop::RtspServer> Server;

    xop::MediaSessionId Session_id;
    FRunnableThread* Thread;

    ISVCEncoder* encoder_ = nullptr;
    SFrameBSInfo info;
    SSourcePicture pic;
    SEncParamBase param;

    int rv;

    cv::Mat imageYuv, imageYuvMini;
    cv::Mat imageYuvCh[3], imageYuvMiniCh[3];
};
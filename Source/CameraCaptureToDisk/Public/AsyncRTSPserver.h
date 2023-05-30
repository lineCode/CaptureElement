#pragma once

#include "AsyncIO.h"
#include "xop/RtspServer.h"

namespace AME
{
    class AsyncRTSPserver;
    class AsyncRTSPframeSender;
}

class AME::AsyncRTSPserver : public AME::IAsync
{

public:
    explicit AsyncRTSPserver(UCameraCaptureManager* manager);
    virtual ~AsyncRTSPserver() override = default;

public:
    virtual bool Init() override; // Do your setup here, allocate memory, ect.
    virtual uint32 Run() override; // Main data processing happens here
    virtual void Stop() override; // Clean up any memory you allocated here

    mutable bool bStop = false;

protected:
    std::shared_ptr<xop::RtspServer> server;
    std::shared_ptr<xop::EventLoop> event_loop;
    xop::MediaSessionId session_id;
    xop::MediaSession* session;

    TUniquePtr<AME::AsyncRTSPframeSender> FrameSender;
};
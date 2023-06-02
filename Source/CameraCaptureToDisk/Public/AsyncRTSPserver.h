#pragma once

#include "xop/RtspServer.h"
#include "AsyncRTSPframeSender.h"

#include "AsyncRTSPserver.generated.h"

UCLASS(Blueprintable)
class UAsyncRTSPserver : public UObject
{
    GENERATED_BODY()
public:
    explicit UAsyncRTSPserver();
    virtual ~UAsyncRTSPserver() override;

    void HelpInitFrameSender(AME::AsyncRTSPframeSender* FrameSender);

    UFUNCTION(BlueprintPure, Category = "RTSPserver")
    static UAsyncRTSPserver* CreateRTSPserver();

protected:
    void Init(); // Do your setup here, allocate memory, ect.
    std::shared_ptr<xop::RtspServer> Server;
    std::shared_ptr<xop::EventLoop> Event_loop;
    xop::MediaSessionId Session_id;
    xop::MediaSession* Session;
};
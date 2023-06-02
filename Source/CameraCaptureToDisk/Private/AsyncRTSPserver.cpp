#include "AsyncRTSPserver.h"

UAsyncRTSPserver::UAsyncRTSPserver()
{
}

UAsyncRTSPserver::~UAsyncRTSPserver()
{
}

void UAsyncRTSPserver::HelpInitFrameSender(AME::AsyncRTSPframeSender* FrameSender)
{
    FrameSender->InitVars(Server, Session_id);
}

UAsyncRTSPserver* UAsyncRTSPserver::CreateRTSPserver()
{
    auto server = NewObject<UAsyncRTSPserver>();
    server->Init();
    return server;
}

void UAsyncRTSPserver::Init()
{
    std::string suffix = "live";
    std::string ip = "127.0.0.1";
    std::string port = "554";
    std::string rtsp_url = "rtsp://" + ip + ":" + port + "/" + suffix;

    Event_loop = std::make_shared<xop::EventLoop>();
    Server = xop::RtspServer::Create(Event_loop.get());

    if (!Server->Start("0.0.0.0", atoi(port.c_str())))
    {
        FString str(port.c_str());
        UE_LOG(LogTemp, Error, TEXT("RTSP Server listen on %s failed."), *str);
        return;
    }

    Server->SetAuthConfig("-_-", "admin", "12345");

    Session = xop::MediaSession::CreateNew("live");
    Session->AddSource(xop::channel_0, xop::H264Source::CreateNew());
    Session->AddNotifyConnectedCallback([](xop::MediaSessionId sessionId, std::string peer_ip, uint16_t peer_port)
        {
            FString str(peer_ip.c_str());
            UE_LOG(LogTemp, Error, TEXT("RTSP client connect, ip=%s, port=%d"), *str, peer_port);
        });

    Session->AddNotifyDisconnectedCallback([](xop::MediaSessionId sessionId, std::string peer_ip, uint16_t peer_port)
        {
            FString str(peer_ip.c_str());
            UE_LOG(LogTemp, Error, TEXT("RTSP client disconnect, ip=%s, port=%d"), *str, peer_port);
        });

    Session_id = Server->AddSession(Session);
}
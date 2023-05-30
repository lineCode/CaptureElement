#include "AsyncRTSPserver.h"
#include "CameraCaptureManager.h"


AME::AsyncRTSPserver::AsyncRTSPserver(UCameraCaptureManager* manager)
{
    Manager = manager;
    Thread = FRunnableThread::Create(this, TEXT("AsyncRTPSmaker"));
}

AME::AsyncRTSPserver::~AsyncRTSPserver()
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

bool AME::AsyncRTSPserver::Init()
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

    FrameSender = MakeUnique<AME::AsyncRTSPframeSender>(server, session_id);
    Manager->FrameSender = FrameSender.Get();

    return true;
}

void AME::AsyncRTSPserver::Stop()
{
    bStop = true;
}

uint32 AME::AsyncRTSPserver::Run()
{
    while (!bStop)
    {
    }
    return 0;
}
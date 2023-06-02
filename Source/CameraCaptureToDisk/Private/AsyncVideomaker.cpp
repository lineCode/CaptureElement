#include "AsyncVideomaker.h"

AME::AsyncVideomaker::AsyncVideomaker()
{
    bRecord.store(false);

    Thread = FRunnableThread::Create(this, TEXT("AsyncVideomaker"));
}

AME::AsyncVideomaker::~AsyncVideomaker()
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

void AME::AsyncVideomaker::InitRecorder(bool state)
{
    std::unique_lock<std::mutex> lockWriter(VideoWriter);

    if (state)
    {
        bRecord.store(false);

        int codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
        double fps = 55.0;

        FileName = FileNameWithLeadingZeros("vid_", ".avi");
        FPaths::MakeStandardFilename(FileName);

        bool status = video_.open(std::string(TCHAR_TO_UTF8(*FileName)), codec, fps, cv::Size(1280, 720));
        UE_LOG(LogTemp, Warning, TEXT("video file path: %s"), *FileName);

        bRecord.store(true);

        cv.notify_one();
    }
    else
    {
        bRecord.store(false);

        if (video_.isOpened())
            video_.release();

        ImageQueue.Empty();
    }
}

bool AME::AsyncVideomaker::Init()
{
    return AME::IAsync::Init();
}

void AME::AsyncVideomaker::Stop()
{
    bRecord.store(false);
    InitRecorder(false);

    AME::IAsync::Stop();
}

uint32 AME::AsyncVideomaker::Run()
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

                std::unique_lock<std::mutex> lockWriter(VideoWriter);
                if (video_.isOpened())
                {
                    video_.write(rawImage);
                }
            }
        }
        else
        {
            cv.wait(lock, [this] {return bStop.load() || bRecord.load(); });
        }
    }
    return 0;
}
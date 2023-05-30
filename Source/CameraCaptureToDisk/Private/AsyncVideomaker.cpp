#include "AsyncVideomaker.h"

AME::AsyncVideomaker::AsyncVideomaker(UCameraCaptureManager* manager) : AME::IAsync(manager)
{
    Thread = FRunnableThread::Create(this, TEXT("AsyncVideomaker"));
}

void AME::AsyncVideomaker::InitRecorder(bool state)
{
    if (state)
    {
        if (video_.isOpened())
            video_.release();

        int codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
        double fps = 55.0;

        FileName = FileNameWithLeadingZeros("vid_", ".avi");
        FPaths::MakeStandardFilename(FileName);

        bool status = video_.open(std::string(TCHAR_TO_UTF8(*FileName)), codec, fps, cv::Size(1280, 720));
        UE_LOG(LogTemp, Warning, TEXT("video file path: %s"), *FileName);

        bRecord = true;

        cv.notify_one();
    }
    else
    {
        bRecord = false;

        if (video_.isOpened())
            video_.release();

        if (!ImageQueue.empty())
        {
            decltype(ImageQueue) empty{};
            std::swap(ImageQueue, empty);
        }
    }
}

bool AME::AsyncVideomaker::Init()
{
    return AME::IAsync::Init();
}

void AME::AsyncVideomaker::Stop()
{
    bRecord = false;

    AME::IAsync::Stop();
}

uint32 AME::AsyncVideomaker::Run()
{
    std::unique_lock<std::mutex> lock(mutex);

    while (!bStop)
    {
        if (bRecord)
        {
            if (!ImageQueue.empty() && video_.isOpened())
            {
                RGBAtoRGB(ImageQueue.front(), rawImage);
                ImageQueue.pop();

                video_.write(rawImage);
            }
        }
        else
        {
            cv.wait(lock, [this] {return bStop || bRecord; });
        }
    }
    return 0;
}
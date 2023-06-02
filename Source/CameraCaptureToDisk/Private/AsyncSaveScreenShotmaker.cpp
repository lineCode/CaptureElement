#include "AsyncSaveScreenShotmaker.h"


AME::AsyncSaveScreenShotmaker::AsyncSaveScreenShotmaker()
{
    Thread = FRunnableThread::Create(this, TEXT("AsyncSaveScreenShotmaker"));
}

AME::AsyncSaveScreenShotmaker::~AsyncSaveScreenShotmaker()
{
    if (Thread)
    {
        // Kill() is a blocking call, it waits for the thread to finish (call Stop() func).
        // Hopefully that doesn't take too long
        Thread->Kill();
        Thread->WaitForCompletion();
        //delete Thread;
    }
}

bool AME::AsyncSaveScreenShotmaker::Init()
{
    return AME::IAsync::Init();
}

void AME::AsyncSaveScreenShotmaker::Stop()
{
    AME::IAsync::Stop();
}

uint32 AME::AsyncSaveScreenShotmaker::Run()
{
    std::unique_lock<std::mutex> lock(mutex);

    while (!bStop)
    {
        cv.wait(lock, [this] {return !ImageQueue.empty() || bStop;});

        if (!ImageQueue.empty())
        {
            //Generate image name
            FileName = FileNameWithLeadingZeros("img_", ".png");

            RGBAtoRGB(ImageQueue.front(), rawImage);
            ImageQueue.pop();

            cv::imwrite(TCHAR_TO_ANSI(*FileName), rawImage);
        }
    }
    return 0;
}
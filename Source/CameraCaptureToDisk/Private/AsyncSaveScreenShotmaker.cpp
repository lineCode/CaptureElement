#include "AsyncSaveScreenShotmaker.h"


AME::AsyncSaveScreenShotmaker::AsyncSaveScreenShotmaker(UCameraCaptureManager* manager) : AME::IAsync(manager)
{
    Thread = FRunnableThread::Create(this, TEXT("AsyncSaveScreenShotmaker"));
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
#include "AsyncSaveScreenShotmaker.h"


AME::AsyncSaveScreenShotmaker::AsyncSaveScreenShotmaker(UCameraCaptureManager* manager) : AME::AsyncIO(manager)
{
    Thread = FRunnableThread::Create(this, TEXT("AsyncSaveScreenShotmaker"));
}

AME::AsyncSaveScreenShotmaker::~AsyncSaveScreenShotmaker()
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

bool AME::AsyncSaveScreenShotmaker::Init()
{
    return AME::AsyncIO::Init();
}

void AME::AsyncSaveScreenShotmaker::Stop()
{
}

uint32 AME::AsyncSaveScreenShotmaker::Run()
{
    while (!bStop)
    {
        if (!ImageQueue.empty())
        {
            //Generate image name
            FileName = FileNameWithLeadingZeros("img_", ".png");

            RGBAtoRGB(ImageQueue.front(), rawImage);
            ImageQueue.pop();

            cv::imwrite(TCHAR_TO_ANSI(*FileName), rawImage);

            ImgCounter++;
        }
    }
    return 0;
}
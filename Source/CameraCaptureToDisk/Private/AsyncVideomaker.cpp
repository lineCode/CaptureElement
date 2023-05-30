#include "AsyncVideomaker.h"

AME::AsyncVideomaker::AsyncVideomaker(UCameraCaptureManager* manager)
{
    Manager = manager;
    Thread = FRunnableThread::Create(this, TEXT("AsyncVideomaker"));
}

AME::AsyncVideomaker::~AsyncVideomaker()
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

void AME::AsyncVideomaker::InitRecorder()
{
    int codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
    double fps = 30.0;
    FString filename = FPaths::ProjectSavedDir() + "capture/";

    filename.Append(FDateTime::Now().ToString());
    filename.Append(".avi");
    FPaths::MakeStandardFilename(filename);
    bool status = video_.open(std::string(TCHAR_TO_UTF8(*filename)), codec, fps, cv::Size(1280, 720));
    UE_LOG(LogTemp, Warning, TEXT("video file path: %s"), *filename);
}

bool AME::AsyncVideomaker::Init()
{
    rawImage = cv::Mat(FrameHeight, FrameWidth, CV_8UC(3), cv::Scalar(0));
    wrappedImage = cv::Mat(FrameHeight, FrameWidth, CV_8UC(4), cv::Scalar(0));
    return true;
}

void AME::AsyncVideomaker::Stop()
{
    bStop = true;
    bRecord = false;
}

uint32 AME::AsyncVideomaker::Run()
{
    while (!bStop)
    {
        if (bRecord)
        {
            if (!ImageQueue.empty() && video_.isOpened())
            {
                ImageCopy = ImageQueue.front();
                ImageQueue.pop();

                memcpy(wrappedImage.data, ImageCopy.GetData(), ImageCopy.Num());
                cv::split(wrappedImage, channels);
                vectorToCombine.push_back(channels[0]);
                vectorToCombine.push_back(channels[1]);
                vectorToCombine.push_back(channels[2]);
                cv::merge(vectorToCombine, rawImage);

                video_.write(rawImage);
                vectorToCombine.clear();
            }
        }
        else
        {
            if (video_.isOpened())
                video_.release();

            if (!ImageQueue.empty())
            {
                decltype(ImageQueue) empty{};
                std::swap(ImageQueue, empty);
            }
        }
    }
    return 0;
}
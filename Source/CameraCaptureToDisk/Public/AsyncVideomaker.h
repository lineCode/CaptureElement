#pragma once

#include "AsyncIO.h"

namespace AME
{
    class AsyncVideomaker;
}

class AME::AsyncVideomaker : public FRunnable
{
public:
    explicit AsyncVideomaker(UCameraCaptureManager* manager);
    virtual ~AsyncVideomaker() override;

public:
    void InitRecorder();
    virtual bool Init() override; // Do your setup here, allocate memory, ect.
    virtual uint32 Run() override; // Main data processing happens here
    virtual void Stop() override; // Clean up any memory you allocated here

    mutable std::queue<TArray64<uint8>> ImageQueue{};
    mutable bool bStop = false;
    mutable bool bRecord = false;

protected:
    cv::VideoWriter video_;

    cv::Mat rawImage;
    std::vector<cv::Mat> vectorToCombine;
    cv::Mat channels[4];
    cv::Mat wrappedImage;
    TArray64<uint8> ImageCopy{};

    int FrameWidth = 1280;
    int FrameHeight = 720;

    UCameraCaptureManager* Manager;
    FRunnableThread* Thread;
};
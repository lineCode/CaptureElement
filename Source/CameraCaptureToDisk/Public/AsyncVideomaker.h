#pragma once

#include "AsyncIO.h"

namespace AME
{
    class AsyncVideomaker;
}

class AME::AsyncVideomaker : public AME::IAsync
{
public:
    explicit AsyncVideomaker();
    virtual ~AsyncVideomaker() override;

public:
    void InitRecorder(bool state);

    virtual bool Init() override; // Do your setup here, allocate memory, ect.
    virtual uint32 Run() override; // Main data processing happens here
    virtual void Stop() override; // Clean up any memory you allocated here

protected:
    cv::VideoWriter video_;
    std::atomic<bool> bRecord;
    std::mutex VideoWriter;
};
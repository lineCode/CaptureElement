#pragma once

#include "AsyncIO.h"

namespace AME
{
    class AsyncSaveScreenShotmaker;
}

class AME::AsyncSaveScreenShotmaker : public AME::IAsync
{

public:
    explicit AsyncSaveScreenShotmaker(UCameraCaptureManager* manager);
    virtual ~AsyncSaveScreenShotmaker() override = default;

public:
    virtual bool Init() override; 
    virtual uint32 Run() override;
    virtual void Stop() override; 
};
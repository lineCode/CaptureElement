#pragma once

#include "AsyncIO.h"

namespace AME
{
    class AsyncSaveScreenShotmaker;
}

class AME::AsyncSaveScreenShotmaker : public AME::AsyncIO
{

public:
    explicit AsyncSaveScreenShotmaker(UCameraCaptureManager* manager);
    virtual ~AsyncSaveScreenShotmaker();

public:
    virtual bool Init() override; 
    virtual uint32 Run() override;
    virtual void Stop() override; 

protected:
    


    FRunnableThread* Thread;
};
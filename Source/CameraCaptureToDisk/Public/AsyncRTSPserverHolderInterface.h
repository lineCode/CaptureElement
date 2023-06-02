#pragma once

#include "AsyncRTSPserver.h"
#include "AsyncRTSPserverHolderInterface.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class URTSPserverHolder : public UInterface
{
    GENERATED_BODY()
};

class IRTSPserverHolder
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent, Category = "RTSPserver")
    UAsyncRTSPserver* IGetRTSPserver();
    /** Add interface function declarations here */
};
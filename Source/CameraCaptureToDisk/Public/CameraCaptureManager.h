// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PreOpenCVHeaders.h"
#include "OpenCVHelper.h"
#include <ThirdParty/OpenCV/include/opencv2/imgproc.hpp>
#include <ThirdParty/OpenCV/include/opencv2/highgui/highgui.hpp>
#include <ThirdParty/OpenCV/include/opencv2/videoio.hpp>
#include <ThirdParty/OpenCV/include/opencv2/core.hpp>
#include <ThirdParty/OpenCV/include/opencv2/imgcodecs.hpp >
#include "PostOpenCVHeaders.h"

#include <codec_api.h>

#include "Components/SceneComponent.h"
#include "CoreMinimal.h"
#include "Containers/Queue.h"
#include "HAL/Runnable.h"

#include "AsyncSaveScreenShotmaker.h"
#include "AsyncVideomaker.h"
#include "AsyncRTSPserver.h"
#include "AsyncRTSPframeSender.h"

#include "CameraCaptureManager.generated.h"

namespace AME
{
    struct FRenderRequestStruct;
    class AsyncSaveScreenShotmaker;
    class AsyncRTSPserver;
    class AsyncVideomaker;
    class AsyncRTSPframeSender;
}

struct AME::FRenderRequestStruct
{
    TArray<FColor> Image;
    FRenderCommandFence RenderFence;
    FRenderRequestStruct(){}
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CAMERACAPTURETODISK_API UCameraCaptureManager : public USceneComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UCameraCaptureManager();
    virtual ~UCameraCaptureManager();

public:
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION(BlueprintCallable, Category = "ImageCapture")
        void MakeScreenShot();

    UFUNCTION(BlueprintCallable, Category = "ImageCapture")
        void SetupCaptureComponent(USceneCaptureComponent2D* captureComponent);

    UFUNCTION(BlueprintCallable, Category = "ImageCapture")
        void StartVideoRecord(bool bState);

    UFUNCTION(BlueprintCallable, Category = "ImageCapture")
        void StartRTPS(bool bState);

    TQueue<TArray64<uint8>> ImagesToStream;

    TUniquePtr<AME::AsyncSaveScreenShotmaker> ScreenShotmaker;
    TUniquePtr<AME::AsyncRTSPserver> RTPSmaker;
    AME::AsyncRTSPframeSender* FrameSender;
    TUniquePtr<AME::AsyncVideomaker> Videomaker;

    int FrameWidth;
    int FrameHeight;

protected:
    // Called when the component spawns
    virtual void BeginPlay() override;
    // Called when the component delete
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

    void MakeRTPSshot();

    // Color Capture Component
    USceneCaptureComponent2D* CaptureComponent;

    UTextureRenderTarget2D* renderTarget2D;

	// ScreenShot Queue
    TQueue<AME::FRenderRequestStruct*> ScreenShotRequestQueue;

    // RTPS and video record Queue
    TQueue<AME::FRenderRequestStruct*> RTPSRequestQueue;

    bool bMakeRTPS = false;
    bool bVideoRecord = false;
};
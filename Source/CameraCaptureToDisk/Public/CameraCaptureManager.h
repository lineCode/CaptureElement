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

#include "xop/RtspServer.h"
#include <codec_api.h>

#include "Components/SceneComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Containers/Queue.h"
#include "HAL/Runnable.h"
#include "CameraCaptureManager.generated.h"

USTRUCT()
struct FRenderRequestStruct
{
    GENERATED_BODY()

    TArray<FColor> Image;
    FRenderCommandFence RenderFence;

    FRenderRequestStruct()
    {
    }
};

USTRUCT()
struct FFloatRenderRequestStruct
{
    GENERATED_BODY()

    TArray<FFloat16Color> Image;
    FRenderCommandFence RenderFence;

    FFloatRenderRequestStruct()
    {
    }
};

class AsyncSaveScreenShotmaker;
class AsyncRTSPserver;
class AsyncVideomaker;
class AsyncRTSPframeSender;

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

    TUniquePtr<AsyncSaveScreenShotmaker> ScreenShotmaker;
    TUniquePtr<AsyncRTSPserver> RTPSmaker;
    AsyncRTSPframeSender* FrameSender;
    TUniquePtr<AsyncVideomaker> Videomaker;

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
    TQueue<FRenderRequestStruct*> ScreenShotRequestQueue;

    // RTPS and video record Queue
    TQueue<FRenderRequestStruct*> RTPSRequestQueue;

    bool bMakeRTPS = false;
    bool bVideoRecord = false;


};

/*
*******************************************************************
*/

class AsyncSaveScreenShotmaker : public FRunnable
{

public:
    explicit AsyncSaveScreenShotmaker(UCameraCaptureManager* manager);
    virtual ~AsyncSaveScreenShotmaker() override;

public:
    virtual bool Init() override; // Do your setup here, allocate memory, ect.
    virtual uint32 Run() override; // Main data processing happens here
    virtual void Stop() override; // Clean up any memory you allocated here

    mutable std::queue<TArray64<uint8>> ImageQueue{};
    mutable bool bStop = false;

protected:
    FString FileName = "";
    int ImgCounter = 0;
    int NumDigits = 6;

    UCameraCaptureManager* Manager;
    FRunnableThread* Thread;

    cv::Mat channels[4];
    std::vector<cv::Mat> vectorToCombine;
    cv::Mat rawImage;

    TArray64<uint8> ImageCopy{};
    // Additional funtion to make filename
    FString ToStringWithLeadingZeros(int32 Integer, int32 MaxDigits);
};


class AsyncRTSPserver : public FRunnable
{

public:
    explicit AsyncRTSPserver(UCameraCaptureManager* manager);
    virtual ~AsyncRTSPserver() override;

public:
    virtual bool Init() override; // Do your setup here, allocate memory, ect.
    virtual uint32 Run() override; // Main data processing happens here
    virtual void Stop() override; // Clean up any memory you allocated here

    mutable bool bStop = false;

protected:
    std::shared_ptr<xop::RtspServer> server;
    std::shared_ptr<xop::EventLoop> event_loop;
    xop::MediaSessionId session_id;
    xop::MediaSession* session;

    TUniquePtr<AsyncRTSPframeSender> FrameSender;

    UCameraCaptureManager* Manager;
    FRunnableThread* Thread;
};

class AsyncRTSPframeSender : public FRunnable
{
public:
    explicit AsyncRTSPframeSender(std::shared_ptr<xop::RtspServer> server, xop::MediaSessionId session_id);
    virtual ~AsyncRTSPframeSender() override;
    mutable std::queue<TArray64<uint8>> ImageQueue{};

public:
    mutable bool bStop = false;
    mutable bool bRecord = false;

    virtual bool Init() override; // Do your setup here, allocate memory, ect.
    virtual uint32 Run() override; // Main data processing happens here
    virtual void Stop() override; // Clean up any memory you allocated here

protected:
    std::shared_ptr<xop::RtspServer> Server;

    xop::MediaSessionId Session_id;
    FRunnableThread* Thread;

    ISVCEncoder* encoder_ = nullptr;
    SFrameBSInfo info;
    SSourcePicture pic;
    SEncParamBase param;

    int rv;
    std::vector<cv::Mat> vectorToCombine;
    cv::Mat channels[4];
    cv::Mat rawImage;
    cv::Mat imageYuv, imageYuvMini;
    cv::Mat imageYuvCh[3], imageYuvMiniCh[3];

    TArray64<uint8> ImageCopy{};
    cv::Mat wrappedImage;

    int FrameWidth = 1280;
    int FrameHeight = 720;
};

class AsyncVideomaker : public FRunnable
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
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class ASceneCapture2D;
class UMaterial;


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

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Containers/Queue.h"
#include "HAL/Runnable.h"
#include "CameraCaptureManager.generated.h"




USTRUCT()
struct FRenderRequestStruct{
    GENERATED_BODY()

    TArray<FColor> Image;
    FRenderCommandFence RenderFence;

    FRenderRequestStruct(){

    }
};


USTRUCT()
struct FFloatRenderRequestStruct{
    GENERATED_BODY()

    TArray<FFloat16Color> Image;
    FRenderCommandFence RenderFence;

    FFloatRenderRequestStruct(){

    }
};

class AsyncSaveScreenShotmaker;
class AsyncRTSPserver;
class AsyncVideomaker;
class AsyncRTSPframeSender;

UCLASS(Blueprintable)
class CAMERACAPTURETODISK_API ACameraCaptureManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraCaptureManager();

    virtual ~ACameraCaptureManager();
    
    // Captured Data Sub-Directory Name 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Capture")
    FString SubDirectoryName = "";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Capture")
    int FrameWidth;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Capture")
    int FrameHeight;

   

	// Color Capture Components
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Capture")
    ASceneCapture2D* CaptureComponent;

    // PostProcessMaterial used for segmentation
    UPROPERTY(EditAnywhere, Category="Capture")
    UMaterial* PostProcessMaterial = nullptr;

    UPROPERTY(EditAnywhere, Category="Logging")
    bool VerboseLogging = false;

protected:
	// ScreenShot Queue
    TQueue<FRenderRequestStruct*> ScreenShotRequestQueue;

    // RTPS and video record Queue
    TQueue<FRenderRequestStruct*> RTPSRequestQueue;

    UTextureRenderTarget2D* renderTarget2D;

    bool bMakeRTPS = false;
    bool bVideoRecord = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    void MakeRTPSshot();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "ImageCapture")
    void MakeScreenShot();

    UFUNCTION(BlueprintCallable, Category = "ImageCapture")
    void SetupCaptureComponent();

    UFUNCTION(BlueprintCallable, Category = "ImageCapture")
    void StartVideoRecord(bool bState);

    UFUNCTION(BlueprintCallable, Category = "ImageCapture")
    void StartRTPS(bool bState);
    
    TQueue<TArray64<uint8>> ImagesToStream;

    AsyncSaveScreenShotmaker* ScreenShotmaker_;

    AsyncRTSPserver* RTPSmaker_;

    AsyncRTSPframeSender* FrameSender_;

    AsyncVideomaker* Videomaker_;
};

/*
*******************************************************************
*/

class AsyncSaveScreenShotmaker : public FRunnable
{
    public:
        explicit AsyncSaveScreenShotmaker(ACameraCaptureManager* manager);
        virtual ~AsyncSaveScreenShotmaker() override;

protected:
    FString FileName = "";
    int ImgCounter = 0;
    int NumDigits = 6;

    ACameraCaptureManager* Manager;
    FRunnableThread* Thread;

    cv::Mat channels[4];
    std::vector<cv::Mat> vectorToCombine;
    cv::Mat rawImage;

    // Additional funtion to make filename
    FString ToStringWithLeadingZeros(int32 Integer, int32 MaxDigits);

public:
    virtual bool Init() override; // Do your setup here, allocate memory, ect.
    virtual uint32 Run() override; // Main data processing happens here
    virtual void Stop() override; // Clean up any memory you allocated here

    mutable TArray64<uint8> ImageCopy {};
    mutable bool bStop = false;
};

class AsyncRTSPserver : public FRunnable
{
public:
    explicit AsyncRTSPserver(ACameraCaptureManager* manager);
    virtual ~AsyncRTSPserver() override;

protected:
    std::shared_ptr<xop::RtspServer> server;
    std::shared_ptr<xop::EventLoop> event_loop;
    xop::MediaSessionId session_id;
    xop::MediaSession* session;

    AsyncRTSPframeSender* FrameSender;

    ACameraCaptureManager* Manager;
    FRunnableThread* Thread;

public:
    virtual bool Init() override; // Do your setup here, allocate memory, ect.
    virtual uint32 Run() override; // Main data processing happens here
    virtual void Stop() override; // Clean up any memory you allocated here

    mutable bool bStop = false;
};

class AsyncRTSPframeSender : public FRunnable
{
public:
    virtual bool Init() override; // Do your setup here, allocate memory, ect.
    virtual uint32 Run() override; // Main data processing happens here
    virtual void Stop() override; // Clean up any memory you allocated here

public:
    explicit AsyncRTSPframeSender(xop::RtspServer* server, xop::MediaSessionId session_id);
    virtual ~AsyncRTSPframeSender() override;
    mutable std::queue<TArray64<uint8>> ImageQueue{};

    mutable bool bStop = false;
    mutable bool bRecord = false;

protected:
    xop::RtspServer* Server;
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
    explicit AsyncVideomaker(ACameraCaptureManager* manager);
    virtual ~AsyncVideomaker() override;

protected:
    cv::VideoWriter video_;
    cv::Mat rawImage;
    std::vector<cv::Mat> vectorToCombine;
    cv::Mat channels[4];

    cv::Mat wrappedImage;
    TArray64<uint8> ImageCopy{};

    int FrameWidth = 1280;
    int FrameHeight = 720;

    ACameraCaptureManager* Manager;
    FRunnableThread* Thread;

public:
    void InitRecorder();
    virtual bool Init() override; // Do your setup here, allocate memory, ect.
    virtual uint32 Run() override; // Main data processing happens here
    virtual void Stop() override; // Clean up any memory you allocated here

    mutable std::queue<TArray64<uint8>> ImageQueue{};
    mutable bool bStop = false;
    mutable bool bRecord = false;
};
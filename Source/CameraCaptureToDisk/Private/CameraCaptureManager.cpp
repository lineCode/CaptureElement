// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraCaptureManager.h"

#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Engine/SceneCapture2D.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Kismet/GameplayStatics.h"
#include "ShowFlags.h"
#include "Materials/Material.h"
#include "RHICommandList.h"

#include "ImageWrapper/Public/IImageWrapper.h"
#include "ImageWrapper/Public/IImageWrapperModule.h"

#include "ImageUtils.h"
#include "Modules/ModuleManager.h"
#include "Misc/FileHelper.h"

#include  <filesystem>

// Sets default values
UCameraCaptureManager::UCameraCaptureManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.TickInterval = 0.015;
}

UCameraCaptureManager::~UCameraCaptureManager()
{
}

void UCameraCaptureManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (ScreenShotmaker.Get())
    {
        ScreenShotmaker.Get()->bStop = true;
    }

    if (RTPSmaker.Get())
    {
        RTPSmaker.Get()->bStop = true;
    }

    if (Videomaker.Get())
    {
        Videomaker.Get()->bStop = true;
    }

    Super::EndPlay(EndPlayReason);
}

// Called when the game starts or when spawned
void UCameraCaptureManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UCameraCaptureManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!CaptureComponent)
    {
    	UE_LOG(LogTemp, Error, TEXT("No CaptureComponent set!"));
        return;
    }
    
    // READ UINT8 IMAGE
	// Read pixels once RenderFence is completed
   
    if(!ScreenShotRequestQueue.IsEmpty())
    {
        // Peek the next RenderRequest from queue
        AME::FRenderRequestStruct* nextRenderRequest = nullptr;
        ScreenShotRequestQueue.Peek(nextRenderRequest);

        if(nextRenderRequest)
        { //nullptr check
            if(nextRenderRequest->RenderFence.IsFenceComplete())
            { // Check if rendering is done, indicated by RenderFence
                // Load the image wrapper module 
                IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));

                // Prepare data to be written to disk
                static TSharedPtr<IImageWrapper> imageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG); //EImageFormat::PNG //EImageFormat::JPEG
                imageWrapper->SetRaw(nextRenderRequest->Image.GetData(), nextRenderRequest->Image.GetAllocatedSize(), FrameWidth, FrameHeight, ERGBFormat::BGRA, 8);
                //const TArray64<uint8>& ImgData = imageWrapper->GetCompressed(5);

                TArray64<uint8> ImgData2;
                imageWrapper->GetRaw(ERGBFormat::BGRA, 8, ImgData2);

                if (ScreenShotmaker.Get())
                {
                    ScreenShotmaker.Get()->ImageQueue.push(ImgData2);
                    ScreenShotmaker.Get()->cv.notify_one();
                }

                // Delete the first element from RenderQueue
                ScreenShotRequestQueue.Pop();
                delete nextRenderRequest;
            }
        }
    }

    if ((bMakeRTPS && RTPSmaker.Get()) || (bVideoRecord && Videomaker.Get()))
    {
        if (!RTPSRequestQueue.IsEmpty())
        {
            // Peek the next RenderRequest from queue
            AME::FRenderRequestStruct* nextRenderRequest = nullptr;
            RTPSRequestQueue.Peek(nextRenderRequest);

            if (nextRenderRequest)
            { //nullptr check
                if (nextRenderRequest->RenderFence.IsFenceComplete())
                { // Check if rendering is done, indicated by RenderFence
                    // Load the image wrapper module 
                    IImageWrapperModule& RTPSImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));

                    // Prepare data to be written to disk
                    static TSharedPtr<IImageWrapper> RTPSimageWrapper = RTPSImageWrapperModule.CreateImageWrapper(EImageFormat::PNG); //EImageFormat::PNG //EImageFormat::JPEG
                    RTPSimageWrapper->SetRaw(nextRenderRequest->Image.GetData(), nextRenderRequest->Image.GetAllocatedSize(), FrameWidth, FrameHeight, ERGBFormat::BGRA, 8);
                    //const TArray64<uint8>& ImgData = imageWrapper->GetCompressed(5);

                    TArray64<uint8> ImgData2;
                    RTPSimageWrapper->GetRaw(ERGBFormat::BGRA, 8, ImgData2);

                    if (FrameSender && bMakeRTPS)
                        FrameSender->ImageQueue.push(ImgData2);

                    if (Videomaker.Get() && bVideoRecord)
                    {
                        Videomaker.Get()->ImageQueue.push(ImgData2);
                    }

                    // Delete the first element from RenderQueue
                    RTPSRequestQueue.Pop();
                    delete nextRenderRequest;
                }
            }
        }
        MakeRTPSshot();
    }
}

void UCameraCaptureManager::StartVideoRecord(bool bState)
{
    bVideoRecord = bState;

    if (Videomaker.Get())
    {
        Videomaker.Get()->InitRecorder(bState);
    }
}

void UCameraCaptureManager::StartRTPS(bool bState)
{
    bMakeRTPS = bState;

    if (FrameSender)
    {
        FrameSender->bRecord = bState;
        FrameSender->cv.notify_one();
    }
}

void UCameraCaptureManager::SetupCaptureComponent(USceneCaptureComponent2D* captureComponent)
{
    CaptureComponent = captureComponent;
    FrameWidth = 1280;
    FrameHeight = 720;

    if(!IsValid(CaptureComponent))
    {
        UE_LOG(LogTemp, Error, TEXT("SetupCaptureComponent: CaptureComponent is not valid!"));
        return;
    }

    // Create RenderTargets
    renderTarget2D = NewObject<UTextureRenderTarget2D>();
    
    renderTarget2D->RenderTargetFormat = ETextureRenderTargetFormat::RTF_RGBA8; //8-bit color format
    renderTarget2D->InitCustomFormat(FrameWidth, FrameHeight, PF_B8G8R8A8, false); // PF... disables HDR, which is most important since HDR gives gigantic overhead, and is not needed!
    UE_LOG(LogTemp, Warning, TEXT("Set Render Format for Color-Like-Captures"));
    
    renderTarget2D->bGPUSharedFlag = true; // demand buffer on GPU

    // Assign RenderTarget
    CaptureComponent->TextureTarget = renderTarget2D;
    // Set Camera Properties
    CaptureComponent->CaptureSource = ESceneCaptureSource::SCS_FinalColorHDR;
    // CaptureComponent->GetCaptureComponent2D()->TextureTarget->TargetGamma = GEngine->GetDisplayGamma();
    //CaptureComponent->GetCaptureComponent2D()->ShowFlags.SetTemporalAA(true);
    
    UE_LOG(LogTemp, Warning, TEXT("Initialized RenderTarget!"));

    renderTarget2D->UpdateResourceImmediate();

    FString test = FPaths::ProjectSavedDir() + "capture";
    FPaths::MakeStandardFilename(test);
    std::filesystem::create_directory(TCHAR_TO_UTF8(*test));

    if (!ScreenShotmaker.Get())
        ScreenShotmaker = MakeUnique<AME::AsyncSaveScreenShotmaker>(this);

    if (!RTPSmaker.Get())
        RTPSmaker = MakeUnique<AME::AsyncRTSPserver>(this);

    if (!Videomaker.Get())
        Videomaker = MakeUnique<AME::AsyncVideomaker>(this);
}

void UCameraCaptureManager::MakeRTPSshot()
{
    if (!IsValid(CaptureComponent))
    {
        UE_LOG(LogTemp, Error, TEXT("CaptureColorNonBlocking: CaptureComponent was not valid!"));
        return;
    }

    // Get RenderConterxt
    FTextureRenderTargetResource* renderTargetResource = CaptureComponent->TextureTarget->GameThread_GetRenderTargetResource();

    struct FReadSurfaceContext
    {
        FRenderTarget* SrcRenderTarget;
        TArray<FColor>* OutData;
        FIntRect Rect;
        FReadSurfaceDataFlags Flags;
    };

    // Init new RenderRequest
    AME::FRenderRequestStruct* renderRequest = new AME::FRenderRequestStruct();


    // Setup GPU command
    FReadSurfaceContext readSurfaceContext = {
        renderTargetResource,
        &(renderRequest->Image),
        FIntRect(0,0,renderTargetResource->GetSizeXY().X, renderTargetResource->GetSizeXY().Y),
        FReadSurfaceDataFlags(RCM_UNorm, CubeFace_MAX)
    };

    ENQUEUE_RENDER_COMMAND(SceneDrawCompletion)(
        [readSurfaceContext](FRHICommandListImmediate& RHICmdList)
        {
            RHICmdList.ReadSurfaceData(
                readSurfaceContext.SrcRenderTarget->GetRenderTargetTexture(),
                readSurfaceContext.Rect,
                *readSurfaceContext.OutData,
                readSurfaceContext.Flags
            );
        });

    // Notifiy new task in RenderQueue
    RTPSRequestQueue.Enqueue(renderRequest);

    // Set RenderCommandFence
    renderRequest->RenderFence.BeginFence();
}


void UCameraCaptureManager::MakeScreenShot()
{
    if(!IsValid(CaptureComponent))
    {
        UE_LOG(LogTemp, Error, TEXT("CaptureColorNonBlocking: CaptureComponent was not valid!"));
        return;
    }
    UE_LOG(LogTemp, Warning, TEXT("Entering: CaptureNonBlocking"));

    // Get RenderConterxt
    FTextureRenderTargetResource* renderTargetResource = CaptureComponent->TextureTarget->GameThread_GetRenderTargetResource();
    UE_LOG(LogTemp, Warning, TEXT("Got display gamma"));
    struct FReadSurfaceContext
    {
        FRenderTarget* SrcRenderTarget;
        TArray<FColor>* OutData;
        FIntRect Rect;
        FReadSurfaceDataFlags Flags;
    };
    UE_LOG(LogTemp, Warning, TEXT("Inited ReadSurfaceContext"));
    // Init new RenderRequest
    AME::FRenderRequestStruct* renderRequest = new AME::FRenderRequestStruct();
    UE_LOG(LogTemp, Warning, TEXT("inited renderrequest"));

    // Setup GPU command
    FReadSurfaceContext readSurfaceContext = {
        renderTargetResource,
        &(renderRequest->Image),
        FIntRect(0,0,renderTargetResource->GetSizeXY().X, renderTargetResource->GetSizeXY().Y),
        FReadSurfaceDataFlags(RCM_UNorm, CubeFace_MAX)
    };
    UE_LOG(LogTemp, Warning, TEXT("GPU Command complete"));

    ENQUEUE_RENDER_COMMAND(SceneDrawCompletion)(
    [readSurfaceContext](FRHICommandListImmediate& RHICmdList)
        {
        RHICmdList.ReadSurfaceData(
            readSurfaceContext.SrcRenderTarget->GetRenderTargetTexture(),
            readSurfaceContext.Rect,
            *readSurfaceContext.OutData,
            readSurfaceContext.Flags
        );
    });

    // Notifiy new task in RenderQueue
    ScreenShotRequestQueue.Enqueue(renderRequest);

    // Set RenderCommandFence
    renderRequest->RenderFence.BeginFence();
}
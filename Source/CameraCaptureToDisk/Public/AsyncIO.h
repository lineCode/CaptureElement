#pragma once

#include "HAL/Runnable.h"
#include "Containers/Array.h"
#include <queue>
#include <condition_variable>
#include <mutex>

#include "PreOpenCVHeaders.h"
#include "OpenCVHelper.h"
#include <ThirdParty/OpenCV/include/opencv2/imgproc.hpp>
#include <ThirdParty/OpenCV/include/opencv2/highgui/highgui.hpp>
#include <ThirdParty/OpenCV/include/opencv2/videoio.hpp>
#include <ThirdParty/OpenCV/include/opencv2/core.hpp>
#include <ThirdParty/OpenCV/include/opencv2/imgcodecs.hpp >
#include "PostOpenCVHeaders.h"

namespace AME
{
	class AsyncIO;
}

class UCameraCaptureManager;

class AME::AsyncIO : public FRunnable
{
public:
	AsyncIO(UCameraCaptureManager* manager) : Manager(manager) {};
	virtual ~AsyncIO() override {};

	std::queue<TArray64<uint8>> ImageQueue {};
	volatile bool bStop = false;
	volatile bool bRecord = false;

	virtual bool Init() override; // Do your setup here, allocate memory, ect. 
	virtual uint32 Run() override = 0;  // Main data processing happens here
	virtual void Stop() override = 0; // Clean up any memory you allocated here

	std::condition_variable cv;

protected:
	UCameraCaptureManager* Manager;
	FString FileName = "";
	cv::Mat rawImage;
	std::mutex mutex;
	int FrameWidth = 1280;
	int FrameHeight = 720;

	/**
	 * removes Alpha channel
	 */
	void RGBAtoRGB(const TArray64<uint8>& source, cv::Mat& dst);

	/**
	 * Create filename from params.
	 * 
	 * @param prefix examples : "img_", "vid_", "screen-", etc.;
	 * @param postfix = file extension. Examples: ".png", ".mp4", etc.;
	 * 
	 * @return filename
	 */
	FString FileNameWithLeadingZeros(FString&& prefix, FString&& postfix);
};

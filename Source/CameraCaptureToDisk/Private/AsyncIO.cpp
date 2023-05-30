#include "AsyncIO.h"

AME::IAsync::~IAsync()
{
    if (Thread)
    {
        // Kill() is a blocking call, it waits for the thread to finish (call Stop() func).
        // Hopefully that doesn't take too long
        Thread->Kill();
        delete Thread;
    }
}

bool AME::IAsync::Init()
{
    rawImage = cv::Mat(FrameHeight, FrameWidth, CV_8UC(3), cv::Scalar(0));
	return true;
}

void AME::IAsync::Stop()
{
    bStop = true;
    cv.notify_one();
}

void AME::IAsync::RGBAtoRGB(const TArray64<uint8>& source, cv::Mat& dst)
{
    cv::Mat wrappedImage(FrameHeight, FrameWidth, CV_8UC(4), cv::Scalar(0));
    std::vector<cv::Mat> vectorToCombine;
    cv::Mat channels[4];

	memcpy(wrappedImage.data, source.GetData(), source.Num());
	cv::split(wrappedImage, channels);
	vectorToCombine.push_back(channels[0]);
	vectorToCombine.push_back(channels[1]);
	vectorToCombine.push_back(channels[2]);

	cv::merge(vectorToCombine, dst);
}

FString AME::IAsync::FileNameWithLeadingZeros(FString&& prefix, FString&& postfix)
{
    int filenum = 0;

    int year, month, day;
    FDateTime::Now().GetDate(year, month, day);
    auto Date = FString::FromInt(year) + "." + FString::FromInt(month) + "." + FString::FromInt(day);

    FString result = FPaths::ProjectSavedDir() + "capture/" + prefix + Date + "-" + FString::FromInt(filenum) + postfix;

    while (FPaths::FileExists(result))
    {
        filenum++;
        result = FPaths::ProjectSavedDir() + "capture/" + prefix + Date + "-" + FString::FromInt(filenum) + postfix;
    };

    return result;
}


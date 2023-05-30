#include "AsyncIO.h"


bool AME::AsyncIO::Init()
{
	return true;
}

void AME::AsyncIO::RGBAtoRGB(const TArray64<uint8>& source, cv::Mat& dst)
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

FString AME::AsyncIO::FileNameWithLeadingZeros(FString&& prefix, FString&& postfix)
{
    return (FPaths::ProjectSavedDir() + "capture/" + FDateTime::Now().ToString() + postfix);
}
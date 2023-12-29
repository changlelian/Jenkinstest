#include "TestFixture.h"

/**
 * @brief Camera
 */

const std::string ErrorDescriptions::success = "";

const std::string ErrorDescriptions::InvalidEnumInput = "Invalid enum input.";
const std::string ErrorDescriptions::Invalid3DRoiInput = "The maximum image si";  // use match 20 byte
const std::string ErrorDescriptions::InvalidParameterInput = "Invalid parameter input.";
const std::string ErrorDescriptions::Invalid2DSharpenFactor = "The valid range of parameter is from 0.000000 to 5.000000. Please check the input value.";
const std::string ErrorDescriptions::Invalid2DExposure = "The valid range of parameter is from 0.100000 to 999.000000. Please check the input value.";
const std::string ErrorDescriptions::Invalid2DGrayValue = "The valid range of parameter is from 0 to 255. Please check the input value.";
const std::string ErrorDescriptions::Invalid2DHDRExposureSequence = "The valid range of parameter is from 0.100000 to 999.000000. Please check the input value.";
const std::string ErrorDescriptions::InvalidLaser2DHDRExposureSequence = "The valid range of parameter is from 4.000000 to 996.000000. Please check the input value.";
const std::string ErrorDescriptions::InvalidLaserPowerLevel = "The valid range of parameter is from 50 to 100. Please check the input value.";
const std::string ErrorDescriptions::InvalidLaserFramePartitionCount = "The valid range of parameter is from 1 to 4. Please check the input value.";

const std::string ErrorDescriptions::Invalid3DExposureRange = "The valid range of parameter is from 0.100000 to 99.000000. Please check the input value.";
const std::string ErrorDescriptions::InvalidLaser3DExposureRange = "The valid range of parameter is from 4.000000 to 96.000000. Please check the input value.";
const std::string ErrorDescriptions::InvalidLSR3DExposureRange = "The valid range of parameter is from 8.000000 to 96.000000. Please check the input value.";
const std::string ErrorDescriptions::InvalidProEnh3DExposureRange = "The valid range of parameter is from 0.100000 to 45.000000. Please check the input value.";

const std::string ErrorDescriptions::Invalid3DGainRange = "The valid range of parameter is from 0.000000 to 16.000000. Please check the input value.";
const std::string ErrorDescriptions::InvalidDepthRange = "The valid range of parameter is from 1 to 5000. Please check the input value.";
const std::string ErrorDescriptions::InvalidFringeContrastThreshold = "The valid range of parameter is from 1 to 100. Please check the input value.";
const std::string ErrorDescriptions::InvalidAttributeName = "Parameter not found, please check the input parameter name.";

const std::string ErrorDescriptions::InvalidEmptyUserSet = "Input user set name is empty.";

mmind::eye::Camera* CameraSDKFixture::gCamPtr = nullptr;
std::string CameraSDKFixture::modelName = "";

int CameraSDKFixture::colorWidthResolution = 0;
int CameraSDKFixture::colorHeightResolution = 0;
int CameraSDKFixture::depthWidthResolution = 0;
int CameraSDKFixture::depthHeightResolution = 0;

void CameraSDKFixture::setCameraObject(mmind::eye::Camera* camPtr) {
    gCamPtr = camPtr;
    mmind::eye::CameraInfo info;
    gCamPtr->getCameraInfo(info);
    modelName = info.model;
    std::cout << info.model << std::endl;


    mmind::eye::CameraResolutions resolution;
    gCamPtr->getCameraResolutions(resolution);
    colorWidthResolution = resolution.texture.width;
    colorHeightResolution = resolution.texture.height;
    depthWidthResolution = resolution.depth.width;
    depthHeightResolution = resolution.depth.height;
}

/**
 * @brief Profiler
 * 
 */
mmind::eye::Profiler* ProfilerSDKFixture::gProPtr = nullptr;
std::string ProfilerSDKFixture::modelName = "";

void ProfilerSDKFixture::setProfilerObject(mmind::eye::Profiler* proPtr) {
    gProPtr = proPtr;
    mmind::eye::ProfilerInfo info;
    gProPtr->getProfilerInfo(info);
    modelName = info.model;
    std::cout << info.model << std::endl;
}



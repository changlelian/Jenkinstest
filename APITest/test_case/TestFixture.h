#pragma once
#include <iostream>
#include "gtest/gtest.h"
#include "profiler/Profiler.h"
#include "area_scan_3d_camera/Camera.h"


/**
 * @brief Camera
 */

class CameraSDKFixture : public ::testing::Test {
public:
    static void setCameraObject(mmind::eye::Camera* camPtr);

    static mmind::eye::Camera* gCamPtr;
    static std::string modelName;
    static int colorWidthResolution;
    static int colorHeightResolution;
    static int depthWidthResolution;
    static int depthHeightResolution;
};




struct ErrorDescriptions {
    // 0 MMIND_STATUS_SUCCESS
    static const std::string success;

    // -4  MMIND_STATUS_OUT_OF_RANGE_ERROR
    static const std::string InvalidEnumInput;
    static const std::string Invalid3DRoiInput;
    static const std::string InvalidParameterInput;
    static const std::string Invalid2DSharpenFactor;
    static const std::string Invalid2DExposure;
    static const std::string Invalid2DGrayValue;
    static const std::string Invalid2DHDRExposureSequence;
    static const std::string InvalidLaser2DHDRExposureSequence;
    static const std::string InvalidLaserPowerLevel;
    static const std::string InvalidLaserFramePartitionCount;

    static const std::string Invalid3DExposureRange;
    static const std::string InvalidLaser3DExposureRange;
    static const std::string InvalidLSR3DExposureRange;
    static const std::string InvalidProEnh3DExposureRange;
    
    static const std::string Invalid3DGainRange;
    static const std::string InvalidDepthRange;
    static const std::string InvalidFringeContrastThreshold;

    // -5   MMIND_STATUS_PARAMETER_ERROR
    static const std::string InvalidAttributeName;

    static const std::string InvalidEmptyUserSet;
};





/**
 * @brief Profiler
 * 
 */
class ProfilerSDKFixture : public ::testing::Test {
public:
    static void setProfilerObject(mmind::eye::Profiler* proPtr);

    static mmind::eye::Profiler* gProPtr;
    static std::string modelName;
};

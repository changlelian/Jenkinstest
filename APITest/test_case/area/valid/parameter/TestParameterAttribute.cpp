#include <iostream>
#include "gtest/gtest.h"
#include "area/CameraFixture.h"
#include "area/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Scanning3D.h"
#include "area_scan_3d_camera/parameters/Scanning2D.h"
#include "area_scan_3d_camera/parameters/PointCloudProcessing.h"
#include "area_scan_3d_camera/parameters/Uhp.h"
#include "area_scan_3d_camera/parameters/Projector.h"
#include "area_scan_3d_camera/parameters/Laser.h"

using namespace mmind::eye;

/**
*  2D Parameters attribute
*/

TEST_F(CameraAttribute, Scan2DExposureMode) {
	std::vector<std::string>vec1{ "Timed", "Auto", "HDR", "Flash" };
	std::vector<std::string>vec2{ "Timed", "Auto", "HDR"};

	switch (get2DExposureModeCamera(modelName))
	{
	case Camera2DExposureMode::Exposure2DModeNoFlash:
	{
		auto* param = testParameterAttribute(gCamPtr, "Scan2DExposureMode", Parameter::_Enum);
		testEnumParameterAttribute(param, vec2.size(), vec2);
		break;
	}
	case Camera2DExposureMode::Exposure2DALLMode:
	{
		auto* param = testParameterAttribute(gCamPtr, "Scan2DExposureMode", Parameter::_Enum);
		testEnumParameterAttribute(param, vec1.size(), vec1);
		break;
	}
	default:
		break;
	}
}

TEST_F(CameraAttribute, Scan2DSharpenFactor) {
	auto* param = testParameterAttribute(gCamPtr, "Scan2DSharpenFactor", Parameter::_Float);
	testDoubleParameterAttribute(param, 0.1, 0.0, 5.0);
}

TEST_F(CameraAttribute, Scan2DExposureTime) {

	switch (get2DExposureCameraType(modelName))
	{
	case Camera2DExposure::Exposure2DOther:
	{
		auto* param = testParameterAttribute(gCamPtr, "Scan2DExposureTime", Parameter::_Float);
		testDoubleParameterAttribute(param, 0.1, 0.1, 999, "ms");
		break;
	}
	case Camera2DExposure::Exposure42D:
	{
		auto* param = testParameterAttribute(gCamPtr, "Scan2DExposureTime", Parameter::_Float);
		testDoubleParameterAttribute(param, 4, 4, 996, "ms");
		break;
	}

	default:
		break;
	}
}

TEST_F(CameraAttribute, Scan2DExpectedGrayValue) {
	auto* param = testParameterAttribute(gCamPtr, "Scan2DExpectedGrayValue", Parameter::_Int);
	testIntParameterAttribute(param, 1, 0, 255);
}

TEST_F(CameraAttribute, Scan2DToneMappingEnable) {
	testParameterAttribute(gCamPtr, "Scan2DToneMappingEnable", Parameter::_Bool);
}

TEST_F(CameraAttribute, Scan2DROI) {
	auto* param = testParameterAttribute(gCamPtr, "Scan2DROI", Parameter::_Roi);
	testRoiParameterAttribute(param, colorWidthResolution, colorHeightResolution);
}

TEST_F(CameraAttribute, Scan2DHDRExposureSequence) {
	switch (get2DExposureCameraType(modelName))
	{
	case Camera2DExposure::Exposure2DOther:
	{
		auto* param = testParameterAttribute(gCamPtr, "Scan2DHDRExposureSequence", Parameter::_FloatArray);
		testDoubleArrayParameterAttribute(param, 0.1, 0.1, 999, "ms");
		break;
	}

	case Camera2DExposure::Exposure42D:
	{
		auto* param = testParameterAttribute(gCamPtr, "Scan2DHDRExposureSequence", Parameter::_FloatArray);
		testDoubleArrayParameterAttribute(param, 4, 4, 996, "ms");
		break;
	}
	default:
		break;
	}
}



/**
*  3D Parameters attribute
*/
TEST_F(CameraAttribute, Scan3DExposureSequence) {
	switch (getCamera3DExposureType(modelName))
	{
	case Camera3DExposure::Exposure83D:
	{
		auto* param = testParameterAttribute(gCamPtr, "Scan3DExposureSequence", Parameter::_FloatArray);
		testDoubleArrayParameterAttribute(param, 4, 8, 96, "ms");
		break;
	}
	case Camera3DExposure::Exposure43D:
	{
		auto* param = testParameterAttribute(gCamPtr, "Scan3DExposureSequence", Parameter::_FloatArray);
		testDoubleArrayParameterAttribute(param, 4, 4, 96, "ms");
		break;
	}
	case Camera3DExposure::Exposure453D:
	{
		auto* param = testParameterAttribute(gCamPtr, "Scan3DExposureSequence", Parameter::_FloatArray);
		testDoubleArrayParameterAttribute(param, 0.1, 0.1, 45, "ms");
		break;
	}
	case Camera3DExposure::Exposure3DOther:
	{
		auto* param = testParameterAttribute(gCamPtr, "Scan3DExposureSequence", Parameter::_FloatArray);
		testDoubleArrayParameterAttribute(param, 0.1, 0.1, 99, "ms");
		break;
	}
	default:
		break;
	}

}

TEST_F(CameraAttribute, Scan3DROI) {
	auto* param = testParameterAttribute(gCamPtr, "Scan3DROI", Parameter::_Roi);
	testRoiParameterAttribute(param, depthWidthResolution, depthHeightResolution);
}

TEST_F(CameraAttribute, Scan3DGain) {
	auto* param = testParameterAttribute(gCamPtr, "Scan3DGain", Parameter::_Float);
	testDoubleParameterAttribute(param, 0.1, 0, 16, "dB");
}

TEST_F(CameraAttribute, DepthRange) {
	auto* param = testParameterAttribute(gCamPtr, "DepthRange", Parameter::_Range);
	testRangeArrayParameterAttribute(param, 1, 1, 5000, "mm");
}



/**
*   Pointcloud attribute
*/
TEST_F(CameraAttribute, PointCloudSurfaceSmoothing) {
	std::vector<std::string>vec{ "Off", "Weak", "Normal", "Strong" };
	auto* param = testParameterAttribute(gCamPtr, "PointCloudSurfaceSmoothing", Parameter::_Enum);
	testEnumParameterAttribute(param, vec.size(), vec);
}

TEST_F(CameraAttribute, PointCloudNoiseRemoval) {
	std::vector<std::string>vec{ "Off", "Weak", "Normal", "Strong" };
	auto* param = testParameterAttribute(gCamPtr, "PointCloudNoiseRemoval", Parameter::_Enum);
	testEnumParameterAttribute(param, vec.size(), vec);
}

TEST_F(CameraAttribute, PointCloudOutlierRemoval) {
	std::vector<std::string>vec{ "Off", "Weak", "Normal", "Strong" };
	auto* param = testParameterAttribute(gCamPtr, "PointCloudOutlierRemoval", Parameter::_Enum);
	testEnumParameterAttribute(param, vec.size(), vec);
}

TEST_F(CameraAttribute, PointCloudEdgePreservation) {
	std::vector<std::string>vec{ "Sharp", "Normal", "Smooth" };
	auto* param = testParameterAttribute(gCamPtr, "PointCloudEdgePreservation", Parameter::_Enum);
	testEnumParameterAttribute(param, vec.size(), vec);
}

TEST_F(CameraAttribute, FringeMinThreshold) {
	auto* param = testParameterAttribute(gCamPtr, "FringeMinThreshold", Parameter::_Int);
	testIntParameterAttribute(param, 1, 1, 100);
}

TEST_F(CameraAttribute, FringeContrastThreshold) {
	auto* param = testParameterAttribute(gCamPtr, "FringeContrastThreshold", Parameter::_Int);
	testIntParameterAttribute(param, 1, 1, 100);
}


/**
*   UHP attribute
*/
TEST_F(CameraAttribute, UhpFringeCodingMode) {
	std::vector<std::string>vec{ "Fast", "Accurate" };

	switch (getCameraType(modelName))
	{
	case CameraType::UHPCamera:
	{	
		auto* param = testParameterAttribute(gCamPtr, "FringeCodingMode", Parameter::_Enum);
		testEnumParameterAttribute(param, vec.size(), vec);
		break;
	}
	default:
		std::cout << "The Camera is Not UHP" << std::endl;
		break;
	}

}

TEST_F(CameraAttribute, UhpCaptureMode) {
	std::vector<std::string>vec{ "Camera1", "Camera2", "Merge"};


	switch (getCameraType(modelName))
	{
	case CameraType::UHPCamera:
	{
		auto* param = testParameterAttribute(gCamPtr, "UhpCaptureMode", Parameter::_Enum);
		testEnumParameterAttribute(param, vec.size(), vec);
		break;
	}
	default:
		std::cout << "The camera is Not UHP" << std::endl;
		break;
	}
}


/**
*   Laser attribute
*/
TEST_F(CameraAttribute, LaserPowerLevel) {

	switch (getCameraType(modelName))
	{
	case CameraType::LaserCamera:
	{
		auto* param = testParameterAttribute(gCamPtr, "LaserPowerLevel", Parameter::_Int);
		testIntParameterAttribute(param, 1, 50, 100, "%");
		break;
	}
	default:
		std::cout << "The camera is Not Laser series" << std::endl;
		break;
	}
}


TEST_F(CameraAttribute, LaserFrameRange) {

	switch (getCameraType(modelName))
	{
	case CameraType::LaserCamera:
	{
		auto* param = testParameterAttribute(gCamPtr, "LaserFrameRange", Parameter::_Range);
		testRangeArrayParameterAttribute(param, 1, 0, 100, "");
		break;
	}
	default:
		std::cout << "The camera is Not Laser series" << std::endl;
		break;
	}
}

TEST_F(CameraAttribute, LaserFringeCodingMode) {
	std::vector<std::string>vec{ "Fast", "Accurate" };

	switch (getCameraType(modelName))
	{
	case CameraType::LaserCamera:
	{
		auto* param = testParameterAttribute(gCamPtr, "LaserFringeCodingMode", Parameter::_Enum);
		testEnumParameterAttribute(param, vec.size(), vec);
		break;
	}
	default:
		std::cout << "The camera is Not Laser series" << std::endl;
		break;
	}
}


TEST_F(CameraAttribute, LaserFramePartitionCount) {

	switch (getCameraType(modelName))
	{
	case CameraType::LaserCamera:
	{
		auto* param = testParameterAttribute(gCamPtr, "LaserFramePartitionCount", Parameter::_Int);
		testIntParameterAttribute(param, 1, 1, 4);
		break;
	}
	default:
		std::cout << "The camera is Not Laser series" << std::endl;
		break;
	}
}


/**
*   Projector attribute
*/
TEST_F(CameraAttribute, ProjectorPowerLevel) {
	std::vector<std::string>vec{ "High", "Normal", "Low" };


	switch (getPowerLevelCameraType(modelName))
	{
	case CameraType::ProjectorPowerLevelCamera:
	{
		auto* param = testParameterAttribute(gCamPtr, "ProjectorPowerLevel", Parameter::_Enum);
		testEnumParameterAttribute(param, vec.size(), vec);
		break;
	}
	default:
		std::cout << "The camera is Not ProjectorPowerLevel series" << std::endl;
		break;
	}
}


TEST_F(CameraAttribute, ProjectorFringeCodingMode) {
	std::vector<std::string>vec{ "Fast", "Accurate" };

	switch (getCodingModeCameraType(modelName))
	{
	case CameraType::ProjectorCodingModeCamera:
	{
		auto* param = testParameterAttribute(gCamPtr, "ProjectorFringeCodingMode", Parameter::_Enum);
		//testEnumParameterAttribute(param, vec.size(), vec);
		break;
	}
	default:
		std::cout << "The camera is Not ProjectorFringeCodingMode series" << std::endl;
		break;
	}
}


TEST_F(CameraAttribute, ProjectorAntiFlickerMode) {
	std::vector<std::string>vec{ "Off", "AC50Hz",  "AC60Hz"};


	switch (getAntiflickerCameraType(modelName))
	{
	case CameraType::ProjectorAntiflickerCamera:
	{
		auto* param = testParameterAttribute(gCamPtr, "AntiFlickerMode", Parameter::_Enum);
		testEnumParameterAttribute(param, vec.size(), vec);
		break;
	}
	default:
		std::cout << "The camera is Not ProjectorAntiflicker series" << std::endl;
		break;
	}
}
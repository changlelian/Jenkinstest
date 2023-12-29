#include <iostream>
#include "gtest/gtest.h"
#include "area/CameraFixture.h"
#include "area/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Projector.h"

using namespace mmind::eye;




INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersProjectorPowerLevel,
	                                          ::testing::Values(std::make_pair("High", 0),
											  					std::make_pair("Normal", 1),
	                                          	                std::make_pair("Low", 2)));
TEST_P(CameraParametersProjectorPowerLevel, ProjectorPowerLevel) {

	std::pair<std::string, int> modeMap = GetParam();
	switch (getPowerLevelCameraType(modelName))
	{
	case CameraType::ProjectorPowerLevelCamera:
	{
		testValue(gCamPtr, projector_setting::PowerLevel::name, modeMap);
		break;
	}
	default:
		std::cout << "The camera is Not Projector PowerLevel Camera series" << std::endl;
		break;
	}
}



INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersProjectorFringeCodingMode,
	                                          ::testing::Values(std::make_pair("Fast", 0),
	                                          	                std::make_pair("Accurate", 1)));
TEST_P(CameraParametersProjectorFringeCodingMode, ProjectorFringeCodingMode) {

	std::pair<std::string, int> modeMap = GetParam();
	switch (getCodingModeCameraType(modelName))
	{
	case CameraType::ProjectorCodingModeCamera:
	{
		testValue(gCamPtr, projector_setting::FringeCodingMode::name, modeMap);
		break;
	}
	default:
		std::cout << "The camera is Not ProjectorCoding Mode Camera series" << std::endl;
		break;
	}
}



INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersProjectorAntiFlickerMode,
	                                          ::testing::Values(std::make_pair("Off", 0),
	                                          	                std::make_pair("AC50Hz", 1),
																std::make_pair("AC60Hz", 2)));
TEST_P(CameraParametersProjectorAntiFlickerMode, ProjectorAntiFlickerMode) {

	std::pair<std::string, int> modeMap = GetParam();
	switch (getAntiflickerCameraType(modelName))
	{
	case CameraType::ProjectorAntiflickerCamera:
	{
		testValue(gCamPtr, projector_setting::AntiFlickerMode::name, modeMap);
		break;
	}
	default:
		std::cout << "The camera is Not Projector AntiFlicker Mode series" << std::endl;
		break;
	}
}
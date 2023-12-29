#include <iostream>
#include "gtest/gtest.h"
#include "TestFixture.h"
#include "area/CameraFixture.h"
#include "area/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Projector.h"

using namespace mmind::eye;

INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersProjectorPowerLevel,
	                                           ::testing::Values(std::make_pair(" ", -1),
	                                           	                 std::make_pair("Test", 3)));
TEST_P(CameraInvalidParametersProjectorPowerLevel, ProjectorPowerLevel) {

	std::pair<std::string, int> modeMap = GetParam();
	switch (getPowerLevelCameraType(modelName))
	{
	case CameraType::ProjectorPowerLevelCamera:
	{
		testInvalidValue(gCamPtr, projector_setting::PowerLevel::name, modeMap,
			                       ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
			                       ErrorDescriptions::InvalidEnumInput,
			                       ErrorStatus::MMIND_STATUS_SUCCESS,
			                       ErrorDescriptions::success);
		break;
	}
	default:
		std::cout << "first:" << modeMap.first << "second:" << modeMap.second << std::endl;
		testInvalidValue(gCamPtr, projector_setting::PowerLevel::name, modeMap,
			                       ErrorStatus::MMIND_STATUS_PARAMETER_ERROR,
			                       ErrorDescriptions::InvalidAttributeName,
			                       ErrorStatus::MMIND_STATUS_PARAMETER_ERROR,
			                       ErrorDescriptions::InvalidAttributeName, false);
		std::cout << "The camera is Not Projector PowerLevel Camera series" << std::endl;
		break;
	}
}


INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersProjectorFringeCodingMode,
	                                          ::testing::Values(std::make_pair(" ", -1),
	                                          	                std::make_pair("Test", 2)));
TEST_P(CameraInvalidParametersProjectorFringeCodingMode, ProjectorPowerLevel) {

	std::pair<std::string, int> modeMap = GetParam();
	switch (getCodingModeCameraType(modelName))
	{
	case CameraType::ProjectorCodingModeCamera:
	{
		testInvalidValue(gCamPtr, projector_setting::FringeCodingMode::name, modeMap,
			ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
			ErrorDescriptions::InvalidEnumInput,
			ErrorStatus::MMIND_STATUS_SUCCESS,
			ErrorDescriptions::success);
		break;
	}
	default:
		testInvalidValue(gCamPtr, projector_setting::FringeCodingMode::name, modeMap,
			ErrorStatus::MMIND_STATUS_PARAMETER_ERROR,
			ErrorDescriptions::InvalidAttributeName,
			ErrorStatus::MMIND_STATUS_PARAMETER_ERROR,
			ErrorDescriptions::InvalidAttributeName, false);
		std::cout << "The camera is Not Projector PowerLevel Camera series" << std::endl;
		break;
	}
}


INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersProjectorAntiFlickerMode,
	                                           ::testing::Values(std::make_pair(" ", -1),
	                                                             std::make_pair("Test", 3)));
TEST_P(CameraInvalidParametersProjectorAntiFlickerMode, ProjectorAntiFlickerMode) {

	std::pair<std::string, int> modeMap = GetParam();
	switch (getAntiflickerCameraType(modelName))
	{
	case CameraType::ProjectorAntiflickerCamera:
	{
		testInvalidValue(gCamPtr, projector_setting::AntiFlickerMode::name, modeMap,
			ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
			ErrorDescriptions::InvalidEnumInput,
			ErrorStatus::MMIND_STATUS_SUCCESS,
			ErrorDescriptions::success);
		break;
	}
	default:
		testInvalidValue(gCamPtr, projector_setting::AntiFlickerMode::name, modeMap,
			ErrorStatus::MMIND_STATUS_PARAMETER_ERROR,
			ErrorDescriptions::InvalidAttributeName,
			ErrorStatus::MMIND_STATUS_PARAMETER_ERROR,
			ErrorDescriptions::InvalidAttributeName, false);
		std::cout << "The camera is Not Projector PowerLevel Camera series" << std::endl;
		break;
	}
}
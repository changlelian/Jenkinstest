#include <iostream>
#include "gtest/gtest.h"
#include "TestFixture.h"
#include "area/CameraFixture.h"
#include "area/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Uhp.h"

using namespace mmind::eye;


// INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersUhpFringeCodingMode,
// 	                                          ::testing::Values(std::make_pair(" ", -1), 
// 																std::make_pair("Test", 2)));
// TEST_P(CameraInvalidParametersUhpFringeCodingMode, UhpFringeCodingMode) {

// 	std::pair<std::string, int> modeMap = GetParam();
	
// 	switch (getSpecificCameraType(modelName))
// 	{
// 	case SpecificCameraType::UHPCamera:
// 	{
// 		testInvalidValue(gCamPtr, uhp_setting::FringeCodingMode::name, modeMap, 
// 								  ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR, 
// 								  ErrorDescriptions::InvalidEnumInput,
// 								  ErrorStatus::MMIND_STATUS_SUCCESS,
// 								  ErrorDescriptions::success);
// 		break;
// 	}
// 	default:
// 		testInvalidValue(gCamPtr, uhp_setting::FringeCodingMode::name, modeMap,
// 			                       ErrorStatus::MMIND_STATUS_PARAMETER_ERROR,
// 			                       ErrorDescriptions::InvalidAttributeName,
// 			                       ErrorStatus::MMIND_STATUS_PARAMETER_ERROR,
// 			                       ErrorDescriptions::InvalidAttributeName, false);
// 		break;
// 	}
// }




INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersUhpCaptureMode,
	                                          ::testing::Values(std::make_pair(" ", -1),
	                                          	                std::make_pair("Test", 3)));
TEST_P(CameraInvalidParametersUhpCaptureMode, UhpCaptureMode) {

	std::pair<std::string, int> modeMap = GetParam();
	switch (getSpecificCameraType(modelName))
	{
	case SpecificCameraType::UHPCamera:
	{
		testInvalidValue(gCamPtr, uhp_setting::CaptureMode::name, modeMap,
			                       ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
			                       ErrorDescriptions::InvalidEnumInput,
			                       ErrorStatus::MMIND_STATUS_SUCCESS,
			                       ErrorDescriptions::success);
		break;
	}
	default:

		testInvalidValue(gCamPtr, uhp_setting::CaptureMode::name, modeMap,
			                      ErrorStatus::MMIND_STATUS_PARAMETER_ERROR,
			                      ErrorDescriptions::InvalidAttributeName,
			                      ErrorStatus::MMIND_STATUS_PARAMETER_ERROR,
			                      ErrorDescriptions::InvalidAttributeName, false);
		break;
	}
}



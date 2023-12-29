#include <iostream>
#include "gtest/gtest.h"
#include "area/CameraFixture.h"
#include "area/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Uhp.h"

using namespace mmind::eye;


// INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersUhpFringeCodingMode,
// 	::testing::ValuesIn(CameraParametersUhpFringeCodingMode::MapGenerator()));
// INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersUhpFringeCodingMode,
// 	                                          ::testing::Values(std::make_pair("Fast", 0),
// 	                                          	                std::make_pair("Accurate", 1)));
// TEST_P(CameraParametersUhpFringeCodingMode, LaserFringeCodingMode) {

// 	std::pair<std::string, int> modeMap = GetParam();
// 	switch (getSpecificCameraType(modelName))
// 	{
// 	case SpecificCameraType::UHPCamera:
// 	{
// 		testValue(gCamPtr, uhp_setting::FringeCodingMode::name, modeMap);
// 		break;
// 	}
// 	default:
// 		std::cout << "The camera is Not UHP series" << std::endl;
// 		break;
// 	}

// }


INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersUhpCaptureMode,
	                                          ::testing::Values(std::make_pair("Camera1", 0),
	                                          	                std::make_pair("Camera2", 1),
																std::make_pair("Merge", 2)));
TEST_P(CameraParametersUhpCaptureMode, LaserFringeCodingMode) {

	std::pair<std::string, int> modeMap = GetParam();
	switch (getSpecificCameraType(modelName))
	{
	case SpecificCameraType::UHPCamera:
	{
		testValue(gCamPtr, uhp_setting::CaptureMode::name, modeMap);
		break;
	}
	default:
		std::cout << "The camera is Not UHP series" << std::endl;
		break;
	}

}

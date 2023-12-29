#include <iostream>
#include "gtest/gtest.h"
#include "area/CameraFixture.h"
#include "area/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Laser.h"

using namespace mmind::eye;


INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersLaserPowerLevel, ::testing::Range(50, 101));
TEST_P(CameraParametersLaserPowerLevel, LaserPowerLevel) {

	const int setValue = GetParam();
	switch (getCameraType(modelName))
	{
	case CameraType::LaserCamera:
	{
		testValue(gCamPtr, laser_setting::PowerLevel::name, setValue);
		break;
	}
	default:
		std::cout << "The camera is Not Laser series" << std::endl;
		break;
	}
}



INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersLaserFringeCodingMode,
											  ::testing::ValuesIn(CameraParametersLaserFringeCodingMode::MapGenerator()));
TEST_P(CameraParametersLaserFringeCodingMode, LaserFringeCodingMode) {

	std::map<std::string, int> modeMap = GetParam();
	switch (getCameraType(modelName))
	{
	case CameraType::LaserCamera:
	{
		testValue(gCamPtr, laser_setting::FringeCodingMode::name, modeMap);
		break;
	}
	default:
		std::cout << "The camera is Not Laser series" << std::endl;
		break;
	}

}

INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersLaserFramePartitionCount, ::testing::Range(1, 5));
TEST_P(CameraParametersLaserFramePartitionCount, LaserFramePartitionCount) {

	const int setValue = GetParam();
	switch (getCameraType(modelName))
	{
	case CameraType::LaserCamera:
	{
		testValue(gCamPtr, laser_setting::FramePartitionCount::name, setValue);
		break;
	}
	default:
		std::cout << "The camera is Not Laser series" << std::endl;
		break;
	}
}
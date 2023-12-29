#include <iostream>
#include "gtest/gtest.h"
#include "area/CameraFixture.h"
#include "area/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Laser.h"

using namespace mmind::eye;



INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersLaserPowerLevel, ::testing::Values(49, 101));
TEST_P(CameraInvalidParametersLaserPowerLevel, LaserPowerLevel) {

	int  setValue = GetParam();
	switch (getCameraType(modelName))
	{
	case CameraType::LaserCamera:
	{
		testInvalidValue(gCamPtr, laser_setting::PowerLevel::name, setValue,
			                       ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
			                       ErrorDescriptions::InvalidLaserPowerLevel,
			                       ErrorStatus::MMIND_STATUS_SUCCESS,
			                       ErrorDescriptions::success);
		break;
	}
	default:
		testInvalidValue(gCamPtr, laser_setting::PowerLevel::name, setValue,
			                       ErrorStatus::MMIND_STATUS_PARAMETER_ERROR,
			                       ErrorDescriptions::InvalidAttributeName,
			                       ErrorStatus::MMIND_STATUS_PARAMETER_ERROR,
			                       ErrorDescriptions::InvalidAttributeName, false);
		std::cout << "The camera is Not Laser series" << std::endl;
		break;
	}
}


INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersLaserFringeCodingMode,
	                                          ::testing::Values(CameraSDKFixture::modelName == "Mech-Eye LSR L" ? std::make_pair("", 3) :
	                                          	                                                                                                                   std::make_pair("Test", 4)
	));
TEST_P(CameraInvalidParametersLaserFringeCodingMode, LaserFringeCodingMode) {

	std::pair<std::string, int>  setValue = GetParam();
	switch (getCameraType(modelName))
	{
	case CameraType::LaserCamera:
	{
		testInvalidValue(gCamPtr, laser_setting::FringeCodingMode::name, setValue,
			                       ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
			                       ErrorDescriptions::InvalidEnumInput,
			                       ErrorStatus::MMIND_STATUS_SUCCESS,
			                       ErrorDescriptions::success);
		break;
	}
	default:
		
		testInvalidValue(gCamPtr, laser_setting::FringeCodingMode::name, setValue,
								   ErrorStatus::MMIND_STATUS_PARAMETER_ERROR,
								   ErrorDescriptions::InvalidAttributeName,
								   ErrorStatus::MMIND_STATUS_PARAMETER_ERROR,
								   ErrorDescriptions::InvalidAttributeName, false);
		std::cout << "The camera is Not Laser series" << std::endl;
		break;
	}
}


INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersLaserFramePartitionCount, ::testing::Values(0, 5));
TEST_P(CameraInvalidParametersLaserFramePartitionCount, Scan2DExpectedGrayValue) {



	int  setValue = GetParam();
	switch (getCameraType(modelName))
	{
	case CameraType::LaserCamera:
	{
		testInvalidValue(gCamPtr, laser_setting::FramePartitionCount::name, setValue,
			                       ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
			                       ErrorDescriptions::InvalidLaserFramePartitionCount,
			                       ErrorStatus::MMIND_STATUS_SUCCESS,
			                       ErrorDescriptions::success);
		break;
	}
	default:

		testInvalidValue(gCamPtr, laser_setting::FramePartitionCount::name, setValue,
								   ErrorStatus::MMIND_STATUS_PARAMETER_ERROR,
								   ErrorDescriptions::InvalidAttributeName,
								   ErrorStatus::MMIND_STATUS_PARAMETER_ERROR,
								   ErrorDescriptions::InvalidAttributeName,false);
		std::cout << "The camera is Not Laser series" << std::endl;
		break;
	}
}

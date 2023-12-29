#include <iostream>
#include "gtest/gtest.h"
#include "area/CameraFixture.h"
#include "area/CameraFunction.h"
#include "area_scan_3d_camera/parameters/PointCloudProcessing.h"

using namespace mmind::eye;

INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersPointCloudSurfaceSmoothing,
											   ::testing::Values(std::make_pair("Off", 0),
	                                           	                 std::make_pair("Weak", 1),
																 std::make_pair("Normal", 2),
																 std::make_pair("Strong", 3)
																 ));
TEST_P(CameraParametersPointCloudSurfaceSmoothing, PointCloudSurfaceSmoothing) {

	std::pair<std::string, int> modeMap = GetParam();
	testValue(gCamPtr, pointcloud_processing_setting::SurfaceSmoothing::name, modeMap);
}


INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersPointCloudNoiseRemoval,
											   ::testing::Values(std::make_pair("Off", 0),
	                                           	                 std::make_pair("Weak", 1),
																 std::make_pair("Normal", 2),
																 std::make_pair("Strong", 3)
																 ));
TEST_P(CameraParametersPointCloudNoiseRemoval, PointCloudNoiseRemoval) {

	std::pair<std::string, int> modeMap = GetParam();
	testValue(gCamPtr, pointcloud_processing_setting::NoiseRemoval::name, modeMap);
}


INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersPointCloudOutlierRemoval,
											   ::testing::Values(std::make_pair("Off", 0),
	                                           	                 std::make_pair("Weak", 1),
																 std::make_pair("Normal", 2),
																 std::make_pair("Strong", 3)
																 ));
TEST_P(CameraParametersPointCloudOutlierRemoval, PointCloudOutlierRemoval) {

	std::pair<std::string, int> modeMap = GetParam();
	testValue(gCamPtr, pointcloud_processing_setting::OutlierRemoval::name, modeMap);
}



INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersPointCloudEdgePreservation,
											   ::testing::Values(std::make_pair("Sharp", 0),
	                                           	                 std::make_pair("Normal", 1),
																 std::make_pair("Smooth", 2)
																 ));
TEST_P(CameraParametersPointCloudEdgePreservation, PointCloudEdgePreservation) {

	std::pair<std::string, int> modeMap = GetParam();
	testValue(gCamPtr, pointcloud_processing_setting::EdgePreservation::name, modeMap);
}


INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersPointCloudFringeContrastThreshold, ::testing::Range(1, 101));
TEST_P(CameraParametersPointCloudFringeContrastThreshold, FringeContrastThreshold) {
	const int setValue = GetParam();
	testValue(gCamPtr, pointcloud_processing_setting::FringeContrastThreshold::name, setValue);
}


INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersPointCloudFringeMinThreshold, ::testing::Range(1, 101));
TEST_P(CameraParametersPointCloudFringeMinThreshold, FringeMinThreshold) {
	const int setValue = GetParam();
	testValue(gCamPtr, pointcloud_processing_setting::FringeMinThreshold::name, setValue);
}

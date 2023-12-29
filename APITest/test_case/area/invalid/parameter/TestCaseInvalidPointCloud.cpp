#include <iostream>
#include "gtest/gtest.h"
#include "area/CameraFixture.h"
#include "area/CameraFunction.h"
#include "area_scan_3d_camera/parameters/PointCloudProcessing.h"

using namespace mmind::eye;

INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersPointCloudSurfaceSmoothing,
											  ::testing::Values(std::make_pair("", -1),  
												                std::make_pair("Test", 4)
											  ));
TEST_P(CameraInvalidParametersPointCloudSurfaceSmoothing, PointCloudSurfaceSmoothing) {

	std::pair<std::string, int> modeMap = GetParam();
	testInvalidValue(gCamPtr, pointcloud_processing_setting::SurfaceSmoothing::name, modeMap,
		                      ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
	                          ErrorDescriptions::InvalidEnumInput,
	                          ErrorStatus::MMIND_STATUS_SUCCESS,
	                          ErrorDescriptions::success);
}




INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersPointCloudNoiseRemoval,
	                                          ::testing::Values(std::make_pair("", -1),
	                                          std::make_pair("Test", 4)
											  ));
TEST_P(CameraInvalidParametersPointCloudNoiseRemoval, PointCloudNoiseRemoval) {
	std::pair<std::string, int> modeMap = GetParam();
	testInvalidValue(gCamPtr, pointcloud_processing_setting::NoiseRemoval::name, modeMap,
	                       	   ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
	                       	   ErrorDescriptions::InvalidEnumInput,
	                       	   ErrorStatus::MMIND_STATUS_SUCCESS,
	                       	   ErrorDescriptions::success);
}



INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersPointCloudOutlierRemoval,
	                                          ::testing::Values(std::make_pair("", -1),
	                                          	                        std::make_pair("Test", 4)
	                                          ));
TEST_P(CameraInvalidParametersPointCloudOutlierRemoval, PointCloudOutlierRemoval) {
	std::pair<std::string, int> modeMap = GetParam();
	testInvalidValue(gCamPtr, pointcloud_processing_setting::OutlierRemoval::name, modeMap,
		                       ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
		                       ErrorDescriptions::InvalidEnumInput,
		                       ErrorStatus::MMIND_STATUS_SUCCESS,
		                       ErrorDescriptions::success);
}



INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersPointCloudEdgePreservation,
	                                          ::testing::Values(std::make_pair("", -1),
	                                                          	        std::make_pair("Test", 3)
	                                         ));
TEST_P(CameraInvalidParametersPointCloudEdgePreservation, PointCloudEdgePreservation) {
	std::pair<std::string, int> modeMap = GetParam();
	testInvalidValue(gCamPtr, pointcloud_processing_setting::EdgePreservation::name, modeMap,
		                       ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
		                       ErrorDescriptions::InvalidEnumInput,
		                       ErrorStatus::MMIND_STATUS_SUCCESS,
		                       ErrorDescriptions::success);
}


INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersPointCloudFringeContrastThreshold,
	                                          ::testing::Values(0,101));
TEST_P(CameraInvalidParametersPointCloudFringeContrastThreshold, FringeContrastThreshold) {
	int modeMap = GetParam();
	testInvalidValue(gCamPtr, pointcloud_processing_setting::FringeContrastThreshold::name, modeMap,
		                       ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
		                       ErrorDescriptions::InvalidFringeContrastThreshold,
		                       ErrorStatus::MMIND_STATUS_SUCCESS,
		                       ErrorDescriptions::success);
}


INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersPointCloudFringeMinThreshold,
	                                          ::testing::Values(0, 101));
TEST_P(CameraInvalidParametersPointCloudFringeMinThreshold, FringeContrastThreshold) {
	int modeMap = GetParam();
	testInvalidValue(gCamPtr, pointcloud_processing_setting::FringeMinThreshold::name, modeMap,
		                      ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
		                      ErrorDescriptions::InvalidFringeContrastThreshold,
		                      ErrorStatus::MMIND_STATUS_SUCCESS,
		                      ErrorDescriptions::success);
}

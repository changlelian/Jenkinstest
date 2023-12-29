#include <iostream>
#include "gtest/gtest.h"
#include "area/CameraFixture.h"
#include "area/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Scanning3D.h"

using namespace mmind::eye;




INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersScan3DExposureSequence,
                                            ::testing::Values(std::vector<double>{0},
															  std::vector<double>{0, 0},
															  std::vector<double>{0, 0, 0},
															  std::vector<double>{999.1},
															  std::vector<double>{999.1, 999.1},
															  std::vector<double>{999.1, 999.1, 999.1}

));
TEST_P(CameraInvalidParametersScan3DExposureSequence, Scan3DExposureSequence) {

	const std::vector<double>  setValue = GetParam();

	switch (getCamera3DExposureType(CameraSDKFixture::modelName))
	{
	case Camera3DExposure::Exposure43D:
		// Laser Camera
		testInvalidValue(gCamPtr, scanning3d_setting::ExposureSequence::name, setValue,
								  ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
								  ErrorDescriptions::InvalidLaser3DExposureRange,
								  ErrorStatus::MMIND_STATUS_SUCCESS,
								  ErrorDescriptions::success);
		break;

	case Camera3DExposure::Exposure83D:
		// LSR Camera
		testInvalidValue(gCamPtr, scanning3d_setting::ExposureSequence::name, setValue,
								  ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
								  ErrorDescriptions::InvalidLSR3DExposureRange,
								  ErrorStatus::MMIND_STATUS_SUCCESS,
								  ErrorDescriptions::success);
		break;

	case Camera3DExposure::Exposure453D:
		// Pro L Enhanced
		testInvalidValue(gCamPtr, scanning3d_setting::ExposureSequence::name, setValue,
								  ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
								  ErrorDescriptions::InvalidProEnh3DExposureRange,
								  ErrorStatus::MMIND_STATUS_SUCCESS,
								  ErrorDescriptions::success);
		break;

	case Camera3DExposure::Exposure3DOther:
		// Other Camera
		testInvalidValue(gCamPtr, scanning3d_setting::ExposureSequence::name, setValue,
								  ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
								  ErrorDescriptions::Invalid3DExposureRange,
								  ErrorStatus::MMIND_STATUS_SUCCESS,
								  ErrorDescriptions::success);
	default:
		break;
	}
}


INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersScan3DGain, ::testing::Values(-0.1, 16.1));
TEST_P(CameraInvalidParametersScan3DGain, UhpFringeCodingMode) {

	const double  setValue = GetParam();
	testInvalidValue(gCamPtr, scanning3d_setting::Gain::name, setValue,
							  ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
						      ErrorDescriptions::Invalid3DGainRange,
						      ErrorStatus::MMIND_STATUS_SUCCESS,
							  ErrorDescriptions::success);
}


INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersScan3DDepthRange,
	                                          ::testing::ValuesIn(CameraInvalidParametersScan3DDepthRange::invalidRangeGenerator()));
TEST_P(CameraInvalidParametersScan3DDepthRange, DepthRange) {

	const Range<int> setRange = GetParam();

	if (setRange.max > 5000) {
		testInvalidValue(gCamPtr, scanning3d_setting::DepthRange::name, setRange,
			             ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
			             ErrorDescriptions::InvalidDepthRange,
			             ErrorStatus::MMIND_STATUS_SUCCESS,
			             ErrorDescriptions::success);
	}
	else
	{
		//std::cout << setRange.min << setRange.max << std::endl;
		testInvalidValue(gCamPtr, scanning3d_setting::DepthRange::name, setRange,
			             ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
			             ErrorDescriptions::InvalidParameterInput,
			             ErrorStatus::MMIND_STATUS_SUCCESS,
			             ErrorDescriptions::success);
	}
}






TEST_F(CameraInvalidParametersScan3DROI, Scan3DROI) {

	mmind::eye::ROI roi1{0, 0, static_cast<size_t>(CameraSDKFixture::depthWidthResolution) + 1,static_cast<size_t>(CameraSDKFixture::depthHeightResolution)},
		            roi2{0, 0, static_cast<size_t>(CameraSDKFixture::depthWidthResolution),static_cast<size_t>(CameraSDKFixture::depthHeightResolution) + 1},
		            roi3{1, 0, static_cast<size_t>(CameraSDKFixture::depthWidthResolution) + 1,static_cast<size_t>(CameraSDKFixture::depthHeightResolution)},
		            roi4{1, 0, static_cast<size_t>(CameraSDKFixture::depthWidthResolution),static_cast<size_t>(CameraSDKFixture::depthHeightResolution) + 1};


	testInvalidValue(gCamPtr, scanning3d_setting::ROI::name,roi1,
					          ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
				              ErrorDescriptions::Invalid3DRoiInput,
				              ErrorStatus::MMIND_STATUS_SUCCESS,
				              ErrorDescriptions::success);

	testInvalidValue(gCamPtr, scanning3d_setting::ROI::name,roi2,
							  ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
							  ErrorDescriptions::Invalid3DRoiInput,
							  ErrorStatus::MMIND_STATUS_SUCCESS,
							  ErrorDescriptions::success);

	testInvalidValue(gCamPtr, scanning3d_setting::ROI::name,roi3,
							  ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
							  ErrorDescriptions::Invalid3DRoiInput,
							  ErrorStatus::MMIND_STATUS_SUCCESS,
							  ErrorDescriptions::success);

	testInvalidValue(gCamPtr, scanning3d_setting::ROI::name,roi4,
							  ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
							  ErrorDescriptions::Invalid3DRoiInput,
							  ErrorStatus::MMIND_STATUS_SUCCESS,
							  ErrorDescriptions::success);
}    
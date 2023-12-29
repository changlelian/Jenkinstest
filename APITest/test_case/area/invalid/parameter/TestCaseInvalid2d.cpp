#include <iostream>
#include "gtest/gtest.h"
#include "area/CameraFixture.h"
#include "area/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Scanning2D.h"

using namespace mmind::eye;

INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersScan2DExposureMode,
	                                          ::testing::Values(CameraSDKFixture::modelName == "Mech-Eye LSR L" ? std::make_pair("", 3) : 
				                                                                                                                                                   std::make_pair("Test",4)
											  ));
TEST_P(CameraInvalidParametersScan2DExposureMode, Scan2DExposureMode) {
	std::pair<std::string, int> modeMap = GetParam();
	testInvalidValue(gCamPtr, scanning2d_setting::ExposureMode::name, modeMap,
		                       ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
		                       ErrorDescriptions::InvalidEnumInput,
		                       ErrorStatus::MMIND_STATUS_SUCCESS,
		                       ErrorDescriptions::success);
}



INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersScan2DExposureTime, ::testing::Values(0, 999.1));
TEST_P(CameraInvalidParametersScan2DExposureTime, Scan2DExposureTimeDouble) {
	const double setValue = GetParam();

	switch (get2DExposureCameraType(CameraSDKFixture::modelName))
	{
	case Camera2DExposure::Exposure42D:
		// Laser Camera
		testInvalidValue(gCamPtr, scanning2d_setting::ExposureTime::name, setValue,
								ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
								ErrorDescriptions::InvalidLaser2DHDRExposureSequence,
								ErrorStatus::MMIND_STATUS_SUCCESS,
								ErrorDescriptions::success);
		break;
	case Camera2DExposure::Exposure2DOther:
		// Other Camera
		testInvalidValue(gCamPtr, scanning2d_setting::ExposureTime::name, setValue,
								ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
								ErrorDescriptions::Invalid2DExposure,
								ErrorStatus::MMIND_STATUS_SUCCESS,
								ErrorDescriptions::success);
	default:
		break;
	}
}



INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersScan2DSharpenFactor, ::testing::Values(-0.1, 16.1));
TEST_P(CameraInvalidParametersScan2DSharpenFactor, Scan3DGain) {

	double  setValue = GetParam();
	testInvalidValue(gCamPtr, scanning2d_setting::SharpenFactor::name, setValue,
	                       	   ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
	                       	   ErrorDescriptions::Invalid2DSharpenFactor,
	                       	   ErrorStatus::MMIND_STATUS_SUCCESS,
	                       	   ErrorDescriptions::success);
}





INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersScan2DExpectedGrayValue, ::testing::Values(-1, 256));
TEST_P(CameraInvalidParametersScan2DExpectedGrayValue, Scan2DExpectedGrayValue) {

	int  setValue = GetParam();
	testInvalidValue(gCamPtr, scanning2d_setting::ExpectedGrayValue::name, setValue,
	                        	ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
	                        	ErrorDescriptions::Invalid2DGrayValue,
	                        	ErrorStatus::MMIND_STATUS_SUCCESS,
	                        	ErrorDescriptions::success);
}


TEST_F(CameraInvalidParametersScan2DROI, Scan2DROI) {

	mmind::eye::ROI roi1{0, 0, static_cast<size_t>(CameraSDKFixture::colorWidthResolution) + 1,static_cast<size_t>(CameraSDKFixture::colorHeightResolution)},
		            roi2{0, 0, static_cast<size_t>(CameraSDKFixture::colorWidthResolution),static_cast<size_t>(CameraSDKFixture::colorHeightResolution) + 1},
		            roi3{1, 0, static_cast<size_t>(CameraSDKFixture::colorWidthResolution) + 1,static_cast<size_t>(CameraSDKFixture::colorHeightResolution)},
		            roi4{1, 0, static_cast<size_t>(CameraSDKFixture::colorWidthResolution),static_cast<size_t>(CameraSDKFixture::colorHeightResolution) + 1};


	testInvalidValue(gCamPtr, scanning2d_setting::AutoExposureROI::name,roi1,
					          ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
				              ErrorDescriptions::Invalid3DRoiInput,
				              ErrorStatus::MMIND_STATUS_SUCCESS,
				              ErrorDescriptions::success);

	testInvalidValue(gCamPtr, scanning2d_setting::AutoExposureROI::name,roi2,
							  ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
							  ErrorDescriptions::Invalid3DRoiInput,
							  ErrorStatus::MMIND_STATUS_SUCCESS,
							  ErrorDescriptions::success);
							  
	testInvalidValue(gCamPtr, scanning2d_setting::AutoExposureROI::name,roi3,
							  ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
							  ErrorDescriptions::Invalid3DRoiInput,
							  ErrorStatus::MMIND_STATUS_SUCCESS,
							  ErrorDescriptions::success);

	testInvalidValue(gCamPtr, scanning2d_setting::AutoExposureROI::name,roi4,
							  ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
							  ErrorDescriptions::Invalid3DRoiInput,
							  ErrorStatus::MMIND_STATUS_SUCCESS,
							  ErrorDescriptions::success);
}    

INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersScan2DHDRExposureSequence,
	                                           ::testing::Values(std::vector<double>{0},
	                                           	                         std::vector<double>{0,0},
	                                           	                         std::vector<double>{0, 0, 0},
	                                           	                         std::vector<double>{0, 0, 0, 0},
	                                           	                         std::vector<double>{0, 0, 0, 0, 0},
	                                           	                         std::vector<double>{999.1},
	                                           	                         std::vector<double>{999.1, 999.1},
	                                           	                         std::vector<double>{999.1, 999.1, 999.1},
	                                           	                         std::vector<double>{999.1, 999.1, 999.1, 999.1},
	                                           	                         std::vector<double>{999.1, 999.1, 999.1, 999.1, 999.1}

));
TEST_P(CameraInvalidParametersScan2DHDRExposureSequence, Scan2DHDRExposureSequence) {

	const std::vector<double>  setValue = GetParam();
	switch (getScanHDRExposureTypeCameraType(CameraSDKFixture::modelName))
	{
	case ScanHDRExposureType::HDR_01_999:
		// Invalid2DHDRExposureSequence
		testInvalidValue(gCamPtr, scanning2d_setting::HDRExposureSequence::name, setValue,
								ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
								ErrorDescriptions::Invalid2DHDRExposureSequence,
								ErrorStatus::MMIND_STATUS_SUCCESS,
								ErrorDescriptions::success);
		break;
	case ScanHDRExposureType::HDR_4_996:
		// InvalidLaser2DHDRExposureSequence
		testInvalidValue(gCamPtr, scanning2d_setting::HDRExposureSequence::name, setValue,
								ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR,
								ErrorDescriptions::InvalidLaser2DHDRExposureSequence,
								ErrorStatus::MMIND_STATUS_SUCCESS,
								ErrorDescriptions::success);
	default:
		break;
	}

}

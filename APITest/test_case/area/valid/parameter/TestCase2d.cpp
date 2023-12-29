#include <iostream>
#include <cmath>
#include "gtest/gtest.h"
#include "area/CameraFixture.h"
#include "area/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Scanning2D.h"

using namespace mmind::eye;




INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraScan2DExposureMode,
	                                           ::testing::Values(std::make_pair("Timed", 0),
	                                           	                 std::make_pair("Auto", 1),
																 std::make_pair("HDR", 2),
																 std::make_pair("Flash", 3)
																 ));
// [Scan2DExposureMode]: Testing the [set/getIntValue] Interface with Normal Values
TEST_P(CameraScan2DExposureMode, CameraScan2DExposureModeEnum) {
	const std::pair<std::string, int> modeMap = GetParam();
	

	switch (get2DExposureModeCamera(CameraSDKFixture::modelName))
	{
	case Camera2DExposureMode::Exposure2DModeNoFlash:
	if (modeMap.first != "Flash"){
		testValue(gCamPtr, scanning2d_setting::ExposureMode::name, modeMap);
	}
		break;
	
	default:
		testValue(gCamPtr, scanning2d_setting::ExposureMode::name, modeMap);
		break;
	}
}



INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraScan2DExposureTime, ::testing::Range(1, 9991));
// [Scan2DExposureTime]: Testing the [set/getIntValue] Interface with Normal Values
TEST_P(CameraScan2DExposureTime, Scan2DExposureTimeDouble) {
	const double setValue = GetParam();
	const double result = fmod(setValue, 4.0);

	switch (get2DExposureCameraType(CameraSDKFixture::modelName))
	{
		case Camera2DExposure::Exposure2DOther:
			testValue(gCamPtr, scanning2d_setting::ExposureTime::name, setValue * 0.1);
			break;

		case Camera2DExposure::Exposure42D:
			if (setValue <= 999 && result ==0.0) {
				testValue(gCamPtr, scanning2d_setting::ExposureTime::name, setValue);
			}
			break;
		default:
			break;
	}
}



INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraScan2DSharpenFactor, ::testing::Range(0, 51));
// [Scan2DSharpenFactor]: Testing the [set/getIntValue] Interface with Normal Values
TEST_P(CameraScan2DSharpenFactor, Scan2DSharpenFactorouble) {
	const double setValue = GetParam() * 0.1;
	// by namespace
	testValue(gCamPtr, scanning2d_setting::SharpenFactor::name, setValue);
}


INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraScan2DExpectedGrayValue, ::testing::Range(0, 256));
// [ExpectedGrayValue]: Testing the [set/getIntValue] Interface with Normal Values
TEST_P(CameraScan2DExpectedGrayValue, Scan2DExpectedGrayValueInt) {
	const int setValue = GetParam();
	// by namespace
	testValue(gCamPtr, scanning2d_setting::ExpectedGrayValue::name, setValue);
}



INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraScan2DToneMappingEnable, ::testing::Bool());
// [Scan2DToneMappingEnable]: Testing the [set/getIntValue] Interface with Normal Values
TEST_P(CameraScan2DToneMappingEnable, Scan2DToneMappingEnable) {
	const bool setValue = GetParam();
	// by namespace
	testValue(gCamPtr, scanning2d_setting::ToneMappingEnable::name, setValue);
}


// [Scan2DROI]: Testing the [set/getIntValue] Interface with Normal Values
TEST_F(CameraScan2DROI, Scan2DROIRoi) {

	// height < width
	for (int roiHeight = 0; roiHeight <= colorHeightResolution; roiHeight++)
	{
		ROI setRoi(0, 0, roiHeight, roiHeight);
		testValue(gCamPtr, scanning2d_setting::AutoExposureROI::name, setRoi);
	}

	ROI setRoi1(0, 0, colorWidthResolution, colorHeightResolution);
	testValue(gCamPtr, scanning2d_setting::AutoExposureROI::name, setRoi1);

	// height < width
	for (int roiHeight = 0; roiHeight <= colorHeightResolution / 2; roiHeight++)
	{
		ROI setRoi(colorWidthResolution/2, colorHeightResolution/2, roiHeight, roiHeight);
		testValue(gCamPtr, scanning2d_setting::AutoExposureROI::name, setRoi);
	}

	ROI setRoi2(colorWidthResolution / 2, colorHeightResolution / 2, colorWidthResolution / 2, colorHeightResolution / 2);
	testValue(gCamPtr, scanning2d_setting::AutoExposureROI::name, setRoi2);

	ROI setRoi3(colorWidthResolution, colorHeightResolution, 0, 0);
	testValue(gCamPtr, scanning2d_setting::AutoExposureROI::name, setRoi3);
}


INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraHDRExposureSequence, ::testing::Range(1, 9991));
// [Scan2DHDRExposureSequence]: Testing the [set/getIntValue] Interface with Normal Values
TEST_P(CameraHDRExposureSequence, Scan2DHDRExposureSequenceFloatArray) {
	const double setValue = GetParam();
	const double result = fmod(setValue, 4.0);

	switch (getScanHDRExposureTypeCameraType(CameraSDKFixture::modelName))
	{
	case ScanHDRExposureType::HDR_01_999:
		testValue(gCamPtr, scanning2d_setting::HDRExposureSequence::name, setValue* 0.1, 5);
		break;

	case ScanHDRExposureType::HDR_4_996:
		if (setValue <= 996 && result == 0.0){
			testValue(gCamPtr, scanning2d_setting::HDRExposureSequence::name, setValue, 5);
		}
		break;
	default:
		break;
	}
}
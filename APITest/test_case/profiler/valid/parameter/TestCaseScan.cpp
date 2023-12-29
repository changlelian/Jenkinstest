#include <iostream>
#include "gtest/gtest.h"
#include "profiler/ProfilerFixture.h"
#include "profiler/ProfilerFunction.h"
#include "profiler/parameters/ScanParameters.h"


INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterDataAcquisitionTriggerSource, 
                                     ::testing::Values(std::make_pair("Software", 0),
                                                       std::make_pair("External", 1)
                                                       ));
// [DepthTriggerSource]: Testing the [set/getEnumValue] Interface with Normal Values
TEST_P(ProfilerParameterDataAcquisitionTriggerSource, DepthTriggerSourceEnumValue) {

	std::pair<std::string, int> modeMap = GetParam();
    std::cout << modeMap.first  << modeMap.second << std::endl;
    testValue(gProPtr, trigger_settings::DataAcquisitionTriggerSource::name, modeMap);
}





INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterSoftwareTriggerRate, 
                                     ::testing::Values(std::make_pair("FixedRate", 0),
                                                       std::make_pair("Encoder", 1)
                                                       ));
// [LineScanTriggerSource]: Testing the [set/getEnumValue] Interface with Normal Values
TEST_P(ProfilerParameterSoftwareTriggerRate, LineScanTriggerSource) {

	std::pair<std::string, int> modeMap = GetParam();
    std::cout << modeMap.first  << modeMap.second << std::endl;
    testValue(gProPtr, trigger_settings::LineScanTriggerSource::name, modeMap);
}




// incomplete
/*
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterLineScanTriggerSource, 
                                     ::testing::Values(std::make_pair("FixedRate", 0),
                                                       std::make_pair("Encoder", 1)
                                                       ));
// [LineScanTriggerSource]: Testing the [set/getEnumValue] Interface with Normal Values
TEST_P(ProfilerParameterLineScanTriggerSource, LineScanTriggerSource) {

	std::pair<std::string, int> modeMap = GetParam();
    std::cout << modeMap.first  << modeMap.second << std::endl;
    testValue(gProPtr, trigger_settings::LineScanTriggerSource::name, modeMap);
}
*/





INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterEncoderTriggerDirection, 
                                     ::testing::Values(std::make_pair("ChannelALeading", 0),
                                                       std::make_pair("ChannelBLeading", 1),
                                                       std::make_pair("Both", 2)
                                                       ));
// [EncoderTriggerDirection]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterEncoderTriggerDirection, EncoderTriggerDirection) {

	std::pair<std::string, int> modeMap = GetParam();
    std::cout << modeMap.first  << modeMap.second << std::endl;
    testValue(gProPtr, trigger_settings::EncoderTriggerDirection::name, modeMap);
}





INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterEncoderTriggerSignalCountingMode, 
                                     ::testing::Values(std::make_pair("Multiple_1", 0),
                                                       std::make_pair("Multiple_2", 1),
                                                       std::make_pair("Multiple_4", 2)
                                                       ));
// [DepthTriggerSource]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterEncoderTriggerSignalCountingMode, EncoderTriggerSignalCountingMode) {

	std::pair<std::string, int> modeMap = GetParam();
    std::cout << modeMap.first  << modeMap.second << std::endl;
    testValue(gProPtr, trigger_settings::EncoderTriggerSignalCountingMode::name, modeMap);
}




INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterEncoderTriggerInterval, ::testing::Range(1, 65537, 65534));
// [EncoderTriggerInterval]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterEncoderTriggerInterval, EncoderTriggerInterval) {
	const int setValue = GetParam();
	// by namespace
	testValue(gProPtr, trigger_settings::EncoderTriggerInterval::name, setValue);
}




INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterScanLineCount, ::testing::Range(16, 60001, 59984));
// [ScanLineCount]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterScanLineCount, ScanLineCount) {
	const int setValue = GetParam();
	// by namespace
	testValue(gProPtr, scan_settings::ScanLineCount::name, setValue);
}




INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterExposureDelay, ::testing::Range(1, 2601));
// [ExposureDelay]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterExposureDelay, ExposureDelay) {
	const int setValue = GetParam();
	// by namespace
	testValue(gProPtr, scan_settings::ExposureDelay::name, setValue);
}




INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterCallbackRetrievalTimeout, ::testing::Range(-1,  60001, 60001));
// [CallbackRetrievalTimeout]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterCallbackRetrievalTimeout, CallbackRetrievalTimeout) {
	const int setValue = GetParam();
	// by namespace
	testValue(gProPtr, scan_settings::CallbackRetrievalTimeout::name, setValue);
}


INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterTiltCorrectionAngle, ::testing::Range(-900,  901));
// [TiltCorrectionAngle]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterTiltCorrectionAngle, TiltCorrectionAngle) {
	const double setValue = GetParam() * 0.100;
	// by namespace
	testValue(gProPtr, correction::TiltCorrectionAngle::name, setValue);
}


INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterHeightCorrectionRatio, ::testing::Range(10,  801));
// [TiltCorrectionAngle]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterHeightCorrectionRatio, TiltCorrectionAngle) {
	const double setValue = GetParam() * 0.0100;
	// by namespace
	testValue(gProPtr, correction::HeightCorrectionRatio::name, setValue);
}

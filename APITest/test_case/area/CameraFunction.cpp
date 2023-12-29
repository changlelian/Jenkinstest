#include "CameraFixture.h"

using namespace mmind::eye;


/*******************************************************************************************************************
*                                                                Camera type
*******************************************************************************************************************/


//[1]
const std::unordered_map<std::string, CameraType> cameraTypeMap = {
    {"Mech-Eye LSR L", CameraType::LaserCamera},
    {"Mech-Eye Laser L", CameraType::LaserCamera},
    {"Mech-Eye DEEP", CameraType::LaserCamera},
    {"Mech-Eye Laser L Enhanced", CameraType::LaserCamera},
    //{"Mech-Eye UHP 140", CameraType::UHPCamera},  

    {"Mech-Eye Log M", CameraType::ProjectorPowerLevelCamera},
    {"Mech-Eye Log S", CameraType::ProjectorPowerLevelCamera},
    {"Mech-Eye NANO", CameraType::ProjectorPowerLevelCamera},
    {"Mech-Eye PRO XS", CameraType::ProjectorPowerLevelCamera},
    {"Mech-Eye PRO M", CameraType::ProjectorPowerLevelCamera},
    {"Mech-Eye PRO S", CameraType::ProjectorPowerLevelCamera},
    {"Mech-Eye S Enhanced", CameraType::ProjectorPowerLevelCamera},
    {"Mech-Eye M Enhanced", CameraType::ProjectorPowerLevelCamera},
    {"Mech-Eye UHP 140", CameraType::ProjectorPowerLevelCamera}
};

//[1]
const std::unordered_map<std::string, CameraType> antiFlickerCameraTypeMap = {
    {"Mech-Eye NANO", CameraType::ProjectorAntiflickerCamera},
    {"Mech-Eye PRO M", CameraType::ProjectorAntiflickerCamera},
    {"Mech-Eye PRO S", CameraType::ProjectorAntiflickerCamera}
};

//[1]
const std::unordered_map<std::string, CameraType> codingModeCameraTypeMap = {
    {"Mech-Eye NANO", CameraType::ProjectorCodingModeCamera},
    {"Mech-Eye PRO M", CameraType::ProjectorCodingModeCamera},
    {"Mech-Eye PRO S", CameraType::ProjectorCodingModeCamera},
    {"Mech-Eye UHP 140", CameraType::ProjectorCodingModeCamera},
    {"Mech-Eye PRO XS", CameraType::ProjectorCodingModeCamera}
};


SpecificCameraType getSpecificCameraType(const std::string& input){
    if (input == "Mech-Eye UHP 140")
        return SpecificCameraType::UHPCamera;
    else if (input == "Mech-Eye Laser L" || input == "Mech-Eye Laser L Enhanced")
        return SpecificCameraType::LaserCameras;
    else
        return SpecificCameraType::OtherCamera;
    
}


ScanHDRExposureType getScanHDRExposureTypeCameraType(const std::string& input){
    if (input == "Mech-Eye Laser L Enhanced" || input == "Mech-Eye Laser L")
        return ScanHDRExposureType::HDR_4_996;
    else
        return ScanHDRExposureType::HDR_01_999;

}

// Temperature
ProjectorTemperatureType getProjectorTemperatureType(const std::string& input){
        static const std::unordered_map<std::string, ProjectorTemperatureType> cameraTemperatureTypeMap = {
        {"Mech-Eye LSR L", ProjectorTemperatureType::TempereatureOfProjector},
        {"Mech-Eye Deep", ProjectorTemperatureType::TempereatureOfProjector},
        {"Mech-Eye Laser L", ProjectorTemperatureType::TempereatureOfProjector},
        {"Mech-Eye Laser Enhanced", ProjectorTemperatureType::TempereatureOfProjector},
        {"Mech-Eye NANO", ProjectorTemperatureType::TempereatureOfProjector},
        {"Mech-Eye PRO M", ProjectorTemperatureType::TempereatureOfProjector},
        {"Mech-Eye PRO S", ProjectorTemperatureType::TempereatureOfProjector},
        {"Mech-Eye DEEP", ProjectorTemperatureType::TempereatureOfProjector},
        {"Mech-Eye PRO XS", ProjectorTemperatureType::TempereatureOfProjector},
        {"Mech-Eye S Enhanced", ProjectorTemperatureType::TempereatureOfProjector},
        {"Mech-Eye M Enhanced", ProjectorTemperatureType::TempereatureOfProjector},
        {"Mech-Eye UHP 140", ProjectorTemperatureType::TempereatureOfProjector},
        {"Mech-Eye Log M", ProjectorTemperatureType::TempereatureOfProjector},
        {"Mech-Eye Log S", ProjectorTemperatureType::TempereatureOfProjector},


    };

    auto it = cameraTemperatureTypeMap.find(input);
    if (it != cameraTemperatureTypeMap.end()) {
        return it->second;
    }

    return ProjectorTemperatureType::TempereatureUnknow;
}

//[1] Check whether it is a UHP or Laser camera
CameraType getCameraType(const std::string& input) {
    auto it = cameraTypeMap.find(input);
    return it != cameraTypeMap.end() ? it->second : CameraType::OtherCamera;
}


//[1] Determine if a camera is available with ProjectorPowerLevel
CameraType getPowerLevelCameraType(const std::string& input) {
    auto it = cameraTypeMap.find(input);
    if (it != cameraTypeMap.end()) {
        return it->second == CameraType::ProjectorPowerLevelCamera ? it->second : CameraType::OtherCamera;
    }
    return CameraType::OtherCamera;
}


//[1] Determine if a camera is available in ProjectorCodingMode
CameraType getCodingModeCameraType(const std::string& input) {
    auto it = codingModeCameraTypeMap.find(input);
    if (it != codingModeCameraTypeMap.end()) {
        return it->second == CameraType::ProjectorCodingModeCamera ? it->second : CameraType::OtherCamera;
    }
    return CameraType::OtherCamera;
}


//[1] Determine if ProjectorAntiflicker is available for the camera
CameraType getAntiflickerCameraType(const std::string& input) {
    auto it = antiFlickerCameraTypeMap.find(input);
    return it != antiFlickerCameraTypeMap.end() ? it->second : CameraType::OtherCamera;
}




//[2] Categorize the configurable camera 2D exposure modes
Camera2DExposureMode get2DExposureModeCamera(const std::string& input) {
    static const std::unordered_map<std::string, Camera2DExposureMode> cameraTypeMap = {
        {"Mech-Eye LSR L", Camera2DExposureMode::Exposure2DModeNoFlash},
        {"Mech-Eye Deep", Camera2DExposureMode::Exposure2DModeNoFlash},
        {"Mech-Eye DEEP", Camera2DExposureMode::Exposure2DModeNoFlash}

    };

    auto it = cameraTypeMap.find(input);
    if (it != cameraTypeMap.end()) {
        return it->second;
    }

    return Camera2DExposureMode::Exposure2DALLMode;
}



//[3] Categorize cameras with the type of 2D exposure time that can be set
Camera2DExposure get2DExposureCameraType(const std::string& input) {
    static const std::unordered_map<std::string, Camera2DExposure> cameraTypeMap = {
        {"Mech-Eye Laser L", Camera2DExposure::Exposure42D},
        {"Mech-Eye Laser L Enhanced", Camera2DExposure::Exposure42D}
    };

    auto it = cameraTypeMap.find(input);
    if (it != cameraTypeMap.end()) {
        return it->second;
    }

    return Camera2DExposure::Exposure2DOther;
}



//[4] Classify cameras with configurable types of 3D exposure times
Camera3DExposure getCamera3DExposureType(const std::string& input) {
    static const std::unordered_map<std::string, Camera3DExposure> cameraTypeMap = {
        {"Mech-Eye Laser L", Camera3DExposure::Exposure43D},
        {"Mech-Eye Laser L Enhanced", Camera3DExposure::Exposure43D},
        {"Mech-Eye LSR L", Camera3DExposure::Exposure83D},
        {"Mech-Eye DEEP", Camera3DExposure::Exposure83D},
        {"Mech-Eye LSR S", Camera3DExposure::Exposure83D},
        {"Mech-Eye Pro L Enhanced", Camera3DExposure::Exposure453D}
    };

    auto it = cameraTypeMap.find(input);
    if (it != cameraTypeMap.end()) {
        return it->second;
    }

    return Camera3DExposure::Exposure3DOther;
}

/*******************************************************************************************************************
*                                                                Function tool
*******************************************************************************************************************/


std::string CurrentTimeToString() {
    auto currentTime = std::chrono::system_clock::now();

    // Converts the current point in time to a time structure
    std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);
    struct std::tm* currentTimeInfo = std::localtime(&currentTimeT);

    // Format the time as a string using the put time function
    std::ostringstream oss;
    oss << std::put_time(currentTimeInfo, "%Y-%m-%d %H:%M:%S");
    std::string formattedTimeStr = oss.str();
    return formattedTimeStr;
}

void ExpectVectorsAlmostEqual(const std::vector<double>& vec1, const std::vector<double>& vec2, double tolerance) {
    ASSERT_EQ(vec1.size(), vec2.size()) << "Vectors are of unequal length";

    for (size_t i = 0; i < vec1.size(); ++i) {
        EXPECT_NEAR(vec1[i], vec2[i], tolerance) << "Vectors differ at index " << i;
    }
}

bool ExpectROIAlmostEqual(const ROI& roi1, const ROI& roi2) {
    if ((roi1.upperLeftX == roi2.upperLeftX) && 
        (roi1.upperLeftY == roi2.upperLeftY) &&
        (roi1.width == roi2.width) &&
        (roi1.height == roi2.height))
        return true;
    return false;
    // EXPECT_EQ(roi1.upperLeftX, roi1.upperLeftX) << "ROI differ at upperLeftX " << roi1.upperLeftX << "   " << roi2.upperLeftX;
    // EXPECT_EQ(roi1.upperLeftY, roi1.upperLeftY) << "ROI differ at upperLeftY " << roi1.upperLeftY << "   " << roi2.upperLeftY;
    // EXPECT_EQ(roi1.width, roi1.width) << "ROI differ at width " << roi1.width << "   " << roi2.width;
    // EXPECT_EQ(roi1.height, roi1.height) << "ROI differ at height " << roi1.height << "   " << roi2.height;
}

void testStautsSuccessful(const ErrorStatus& status, int code, std::string description, bool isMatch) {
    EXPECT_EQ(status.errorCode, code);
    
    if (isMatch) {
        EXPECT_EQ(status.errorDescription, description);
    } else{
        EXPECT_EQ(status.errorDescription.substr(0,20), description);
    }
}

void isIncludeUserSet(UserSetManager& usm, const std::string& userSetName, bool flag) {
    std::vector<std::string> userSets;
    testStautsSuccessful(usm.getAllUserSetNames(userSets));
    bool found = std::find(userSets.begin(), userSets.end(), userSetName) != userSets.end();
    
    if (flag == found) {
        FAIL();
    }
}


/*******************************************************************************************************************
*                                                                Valid Parameter Test
*******************************************************************************************************************/

// test int value [start value: 0]
void testValue(mmind::eye::Camera* camera, const std::string& parameterName, const int& setValue) {
    // by name
    int getValue;
    testStautsSuccessful(camera->currentUserSet().setIntValue(parameterName, setValue));
    testStautsSuccessful(camera->currentUserSet().getIntValue(parameterName, getValue));
    EXPECT_EQ(setValue, getValue);
    std::cout << "setIntValue: " << setValue << "  ->  " << "getIntValue: " << getValue << std::endl;
    
    // by child class
    int step, min, max;
    auto* parameter = camera->currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<IntParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    testStautsSuccessful(parameterValue->getStep(step));
    testStautsSuccessful(parameterValue->getMin(min));
    testStautsSuccessful(parameterValue->getMax(max));

    int getValue2;
    testStautsSuccessful(parameterValue->setValue(max - setValue + min));
    testStautsSuccessful(parameterValue->getValue(getValue2));
    EXPECT_EQ(max - setValue  + min, getValue2);
    std::cout << "setIntValue: " << max - setValue + min << "  ->  " << "getIntValue: " << getValue2 << std::endl;

}

// Test double value  [start value: 0.1]
void testValue(mmind::eye::Camera* camera, const std::string& parameterName, const double& setValue) {
    // by name

    double getValue;
    testStautsSuccessful(camera->currentUserSet().setFloatValue(parameterName, setValue));
    testStautsSuccessful(camera->currentUserSet().getFloatValue(parameterName, getValue));
    EXPECT_NEAR(setValue, getValue, 0.08);
    std::cout << "setDoubleValue: " << setValue << "  ->  " << "getDoubleValue: " << getValue << std::endl;

    // by child class
    double step, min, max;
    auto* parameter = camera->currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<FloatParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    testStautsSuccessful(parameterValue->getStep(step));
    testStautsSuccessful(parameterValue->getMin(min));
    testStautsSuccessful(parameterValue->getMax(max));

    double getValue2;
    testStautsSuccessful(parameterValue->setValue(setValue));
    testStautsSuccessful(parameterValue->getValue(getValue2));
    EXPECT_NEAR(setValue, getValue2, 0.08);
    std::cout << "setDoubleValue: " << setValue << "  ->  " << "getDoubleValue: " << getValue2 << std::endl;

}

// Test bool value  [start value: 0.1]
void testValue(mmind::eye::Camera* camera, const std::string& parameterName, const bool& setValue) {
    // by name
    bool getValue;
    testStautsSuccessful(camera->currentUserSet().setBoolValue(parameterName, setValue));
    testStautsSuccessful(camera->currentUserSet().getBoolValue(parameterName, getValue));
    EXPECT_EQ(setValue, getValue);
    std::cout << "setBoolValue: " << setValue << "  ->  " << "getBoolValue: " << getValue << std::endl;

    // by child class
    bool getBoolValue;
    auto* parameter = camera->currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<BoolParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    testStautsSuccessful(parameterValue->setValue(setValue));
    testStautsSuccessful(parameterValue->getValue(getBoolValue));
    EXPECT_EQ(setValue, getBoolValue);

    std::cout << "setBoolValue: " << setValue << "  ->  " << "getBoolValue: " << getBoolValue << std::endl;

}

// Test Enum value  
void testValue(mmind::eye::Camera* camera, const std::string& parameterName, const std::map<std::string, int>& setValueList) {

    //  Cannot merge the two for loops
    for (const auto& modePair : setValueList) {
        std::string getModeName;
        // set int
        testStautsSuccessful(camera->currentUserSet().setEnumValue(parameterName, modePair.second));
        // get string
        testStautsSuccessful(camera->currentUserSet().getEnumValue(parameterName, getModeName));
        EXPECT_EQ(getModeName, modePair.first);
        std::cout << getModeName << "  ->  " << modePair.first << std::endl;
    }

    for (const auto& modePair : setValueList) {
        int getModeValue;
        // set string
        testStautsSuccessful(camera->currentUserSet().setEnumValue(parameterName, modePair.first));
        // get int
        testStautsSuccessful(camera->currentUserSet().getEnumValue(parameterName, getModeValue));
        EXPECT_EQ(getModeValue, modePair.second);
        std::cout << getModeValue << "  ->  " << modePair.second << std::endl;
    }

    auto* parameter = camera->currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<EnumParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    //  Cannot merge the two for loops
    for (const auto& modePair : setValueList) {
        std::string getModeName;
        // set int
        testStautsSuccessful(parameterValue->setValue(modePair.second));
        // get string
        testStautsSuccessful(parameterValue->getValue(getModeName));
        EXPECT_EQ(getModeName, modePair.first);
        std::cout << getModeName << "  ->  " << modePair.first << std::endl;

    }

    for (const auto& modePair : setValueList) {
        int getModeValue;
        // set string
        testStautsSuccessful(parameterValue->setValue(modePair.first));
        // get int
        testStautsSuccessful(parameterValue->getValue(getModeValue));
        EXPECT_EQ(getModeValue, modePair.second);
        std::cout << getModeValue << "  ->  " << modePair.second << std::endl;

    }

    std::map<std::string, int> getValueList;
    testStautsSuccessful(parameterValue->getValues(getValueList));
    EXPECT_EQ(getValueList, setValueList);
}

// Test Enum value  
void testValue(mmind::eye::Camera* camera, const std::string& parameterName, const std::pair<std::string, int>& modePair) {

    //  Cannot merge the two for loops
    std::string getModeName;
    // set int
    testStautsSuccessful(camera->currentUserSet().setEnumValue(parameterName, modePair.second));
    // get string
    testStautsSuccessful(camera->currentUserSet().getEnumValue(parameterName, getModeName));
    EXPECT_EQ(getModeName, modePair.first);
    std::cout << getModeName << "  ->  " << modePair.first << std::endl;


    int getModeValue;
    // set string
    testStautsSuccessful(camera->currentUserSet().setEnumValue(parameterName, modePair.first));
    // get int
    testStautsSuccessful(camera->currentUserSet().getEnumValue(parameterName, getModeValue));
    EXPECT_EQ(getModeValue, modePair.second);
    std::cout << getModeValue << "  ->  " << modePair.second << std::endl;


    auto* parameter = camera->currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<EnumParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    //  Cannot merge the two for loops

    std::string getModeName1;
    // set int
    testStautsSuccessful(parameterValue->setValue(modePair.second));
    // get string
    testStautsSuccessful(parameterValue->getValue(getModeName1));
    EXPECT_EQ(getModeName1, modePair.first);
    std::cout << getModeName1 << "  ->  " << modePair.first << std::endl;



 
    int getModeValue1;
    // set string
    testStautsSuccessful(parameterValue->setValue(modePair.first));
    // get int
    testStautsSuccessful(parameterValue->getValue(getModeValue1));
    EXPECT_EQ(getModeValue1, modePair.second);
    std::cout << getModeValue1 << "  ->  " << modePair.second << std::endl;



    std::map<std::string, int> getValueList;
    testStautsSuccessful(parameterValue->getValues(getValueList));
    EXPECT_NE(getValueList.size(), 0);
}

// Test double array value
void testValue(mmind::eye::Camera* camera, const std::string& parameterName, const double& setValue, const int& repeat){

    for (int rep = 1; rep < repeat; ++rep)
    {
        // by name
        std::vector<double> getArrayValue;
        std::vector<double> setArrayValue(rep, setValue);
        testStautsSuccessful(camera->currentUserSet().setFloatArrayValue(parameterName, setArrayValue));
        testStautsSuccessful(camera->currentUserSet().getFloatArrayValue(parameterName, getArrayValue));
        ExpectVectorsAlmostEqual(setArrayValue, getArrayValue, 0.1);
    }

    // by child class
    double step, min, max;
    int asize;

    auto* parameter = camera->currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<FloatArrayParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    parameterValue->getStep(step);
    parameterValue->getMin(min);
    parameterValue->getMax(max);
    parameterValue->getMaxArraySize(asize);
    for (int rep = 1; rep < repeat; ++rep)
    {
        std::vector<double> getArrayValue;
        std::vector<double> setArrayValue(rep, setValue);
        parameterValue->setValue(setArrayValue);
        parameterValue->getValue(getArrayValue);
        ExpectVectorsAlmostEqual(setArrayValue, getArrayValue, 0.1);
    }
}

// Test Range value 
void testValue(mmind::eye::Camera* camera, const std::string& parameterName, const int& setValue, const int& winSize) {
    // TestCase: 1 -> setValue + 1
    Range<int> setRange(1, setValue + 1) , getRange;
    testStautsSuccessful(camera->currentUserSet().setRangeValue(parameterName, setRange));
    testStautsSuccessful(camera->currentUserSet().getRangeValue(parameterName, getRange));
    EXPECT_EQ(setRange.min, getRange.min);
    EXPECT_EQ(setRange.max, getRange.max);
    std::cout << "setRange:  [" << setRange.min << "," << setRange.max << "]  ->  " 
                   << "getRange:  [" << getRange.min << "," << getRange.max << "]"
                   << std::endl;


    // by child class
    auto* parameter = camera->currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<RangeParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    
    int getStep, getMin, getMax;
    std::string getUnit;
    testStautsSuccessful(parameterValue->getStep(getStep));
    testStautsSuccessful(parameterValue->getMin(getMin));
    testStautsSuccessful(parameterValue->getMax(getMax));
    testStautsSuccessful(parameterValue->getUnit(getUnit));

    Range<int> setRange1(1, getMax + 1 - setValue), getRange1;
    testStautsSuccessful(parameterValue->setValue(setRange1));
    testStautsSuccessful(parameterValue->getValue(getRange1));

    std::cout << "setRange:  [" << setRange1.min << "," << setRange1.max << "]  ->  "
                   << "getRange:  [" << getRange1.min << "," << getRange1.max << "]"
                   << std::endl;

    // TestCase: slide windows, window width = winSize
    if ((setValue + winSize) <= 5000) {
        Range<int> setRange(setValue, setValue + winSize), getRange;
        testStautsSuccessful(camera->currentUserSet().setRangeValue(parameterName, setRange));
        testStautsSuccessful(camera->currentUserSet().getRangeValue(parameterName, getRange));
        EXPECT_EQ(setRange.min, getRange.min);
        EXPECT_EQ(setRange.max, getRange.max);
        std::cout << "setRange:  [" << setRange.min << "," << setRange.max << "]  ->  "
                       << "getRange:  [" << getRange.min << "," << getRange.max << "]"
                       << std::endl;


        Range<int> setRange1(getMax - setValue - winSize + 1, getMax - setValue + 1), getRange1;
        testStautsSuccessful(parameterValue->setValue(setRange1));
        testStautsSuccessful(parameterValue->getValue(getRange1));

        std::cout << "setRange:  [" << setRange1.min << "," << setRange1.max << "]  ->  "
                       << "getRange:  [" << getRange1.min << "," << getRange1.max << "]"
                       << std::endl;
    }


}

// Test ROI value  [start value: 0.1]
void testValue(mmind::eye::Camera* camera, const std::string& parameterName, const ROI& setRoi) {
    // by name
    ROI getRoi;
    testStautsSuccessful(camera->currentUserSet().setRoiValue(parameterName, setRoi));
    testStautsSuccessful(camera->currentUserSet().getRoiValue(parameterName, getRoi));
    std::cout << "setROI: [" << setRoi.upperLeftX << "," << setRoi.upperLeftY << "," << setRoi.width << "," << setRoi.height << "]    ->    "
                   << "getROI: [" << getRoi.upperLeftX << "," << getRoi.upperLeftY << "," << getRoi.width << "," << getRoi.height << "]"
                   << std::endl;
    EXPECT_TRUE(ExpectROIAlmostEqual(setRoi, getRoi));

    // by child class
    auto* parameter = camera->currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<RoiParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    ROI getRoiValue;
    testStautsSuccessful(parameterValue->setValue(setRoi));
    testStautsSuccessful(parameterValue->getValue(getRoiValue));
    EXPECT_TRUE(ExpectROIAlmostEqual(setRoi, getRoiValue));
    std::cout << "setROI: [" << setRoi.upperLeftX << "," << setRoi.upperLeftY << "," << setRoi.width << "," << setRoi.height << "]    ->    "
                   << "getROI: [" << getRoiValue.upperLeftX << "," << getRoiValue.upperLeftY << "," << getRoiValue.width << "," << getRoiValue.height << "]"
                   << std::endl;
}



/*******************************************************************************************************************
*                                                             Invalid Parameter Test
*******************************************************************************************************************/


// Test invalid int value
void testInvalidValue(mmind::eye::Camera* camera, const std::string& parameterName, const int& setValue,
                                  const int& setCode, const std::string& setDescription,
                                  const int& getCode, const std::string& getDescription,
                                  const bool& otherCameraFlag)
{
    // by name
    int getValue;
    testStautsSuccessful(camera->currentUserSet().setIntValue(parameterName, setValue), setCode, setDescription);
    testStautsSuccessful(camera->currentUserSet().getIntValue(parameterName, getValue), getCode, getDescription);
    EXPECT_NE(setValue, getValue);
    std::cout << "setIntValue: " << setValue << "  ->  " << "getIntValue: " << getValue << std::endl;

    // by child class
    int step, min, max;
    auto* parameter = camera->currentUserSet().getParameter(parameterName);
    if (!otherCameraFlag)
        EXPECT_FALSE(parameter);
    else
    {
        EXPECT_TRUE(parameter);

        auto* parameterValue = dynamic_cast<IntParameter*>(parameter);
        EXPECT_TRUE(parameterValue);

        testStautsSuccessful(parameterValue->getStep(step));
        testStautsSuccessful(parameterValue->getMin(min));
        testStautsSuccessful(parameterValue->getMax(max));

        int getValue2;
        testStautsSuccessful(parameterValue->setValue(setValue), setCode, setDescription);
        testStautsSuccessful(parameterValue->getValue(getValue2), getCode, getDescription);
        EXPECT_NE(setValue, getValue2);
        std::cout << "setIntValue: " << setValue << "  ->  " << "getIntValue: " << getValue2 << std::endl;
    }


}


// Test invalid Depth Range value
void testInvalidValue(mmind::eye::Camera* camera, const std::string& parameterName,
                                   const Range<int>& setRange,
                                   const int& setCode, const std::string& setDescription,
                                   const int& getCode, const std::string& getDescription)
{


    // by name
    Range<int> getRange;
    testStautsSuccessful(camera->currentUserSet().setRangeValue(parameterName, setRange), setCode, setDescription);
    testStautsSuccessful(camera->currentUserSet().getRangeValue(parameterName, getRange), getCode, getDescription);


    auto* parameter = camera->currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<RangeParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    testStautsSuccessful(parameterValue->setValue(setRange), setCode, setDescription);
    testStautsSuccessful(parameterValue->getValue(getRange), getCode, getDescription);
}


// Test invalid double array value
void testInvalidValue(mmind::eye::Camera* camera, const std::string& parameterName, 
                                  const std::vector<double>& setArrayValue, 
                                  const int& setCode, const std::string& setDescription,
                                  const int& getCode, const std::string& getDescription)
 {


     // by name
    std::vector<double> getArrayValue;
    testStautsSuccessful(camera->currentUserSet().setFloatArrayValue(parameterName, setArrayValue), setCode, setDescription);
    testStautsSuccessful(camera->currentUserSet().getFloatArrayValue(parameterName, getArrayValue), getCode, getDescription);


    // by child class
    auto* parameter = camera->currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<FloatArrayParameter*>(parameter);
    if (!parameterValue)
        FAIL();


    testStautsSuccessful(parameterValue->setValue(setArrayValue), setCode, setDescription);
    testStautsSuccessful(parameterValue->getValue(getArrayValue), getCode, getDescription);
}


// Test invalid double value
void testInvalidValue(mmind::eye::Camera* camera, const std::string& parameterName, const double& setValue,
                                   const int& setCode, const std::string& setDescription, 
                                   const int& getCode, const std::string& getDescription) 
{
    // by name
    double getValue;
    testStautsSuccessful(camera->currentUserSet().setFloatValue(parameterName, setValue), setCode, setDescription);
    testStautsSuccessful(camera->currentUserSet().getFloatValue(parameterName, getValue), getCode, getDescription);
    EXPECT_NE(setValue, getValue);
    std::cout << "setDoubleValue: " << setValue << "  ->  " << "getDoubleValue: " << getValue << std::endl;

    // by child class
    double step, min, max;
    auto* parameter = camera->currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<FloatParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    testStautsSuccessful(parameterValue->getStep(step));
    testStautsSuccessful(parameterValue->getMin(min));
    testStautsSuccessful(parameterValue->getMax(max));

    double getValue2;
    testStautsSuccessful(parameterValue->setValue(setValue), setCode, setDescription);
    testStautsSuccessful(parameterValue->getValue(getValue2), getCode, getDescription);
    EXPECT_NE(setValue, getValue2);
    std::cout << "setDoubleValue: " << setValue << "  ->  " << "getDoubleValue: " << getValue2 << std::endl;

}

// Test invalid Roi value
void testInvalidValue(mmind::eye::Camera* camera, const std::string& parameterName,const ROI& setRoi,
                                   const int& setCode, const std::string& setDescription, 
                                   const int& getCode, const std::string& getDescription)
{
    // by name
    ROI getRoi;
    testStautsSuccessful(camera->currentUserSet().setRoiValue(parameterName, setRoi), setCode, setDescription, false);  // use match
    testStautsSuccessful(camera->currentUserSet().setRoiValue(parameterName, getRoi), getCode, getDescription, false);  // use match
    EXPECT_FALSE(ExpectROIAlmostEqual(setRoi, getRoi));

    //std::cout << "setDoubleValue: " << setValue << "  ->  " << "getDoubleValue: " << getValue << std::endl;

    // by child class
    auto* parameter = camera->currentUserSet().getParameter(parameterName);
    EXPECT_TRUE(parameter);
    
    auto* parameterValue = dynamic_cast<RoiParameter*>(parameter);
    EXPECT_TRUE(parameterValue);

    ROI getRoi1;
    testStautsSuccessful(parameterValue->setValue(setRoi), setCode, setDescription, false);  // use match
    testStautsSuccessful(parameterValue->getValue(getRoi1));
    EXPECT_FALSE(ExpectROIAlmostEqual(setRoi, getRoi1));
}

// Test invalid Enum value
void testInvalidValue(mmind::eye::Camera* camera, const std::string& parameterName, const std::map<std::string, int>& setValueList,
                                   const int& setCode,  const std::string& setDescription,
                                   const int& getCode, const std::string& getDescription)
{
    for (const auto& modePair : setValueList) {

        int getModeValue;
        std::string getModeString;
        // set string
        testStautsSuccessful(camera->currentUserSet().setEnumValue(parameterName, modePair.first), setCode, setDescription);
        // get string
        testStautsSuccessful(camera->currentUserSet().getEnumValue(parameterName, getModeString), getCode, getDescription);
        // set int
        testStautsSuccessful(camera->currentUserSet().setEnumValue(parameterName, modePair.second), setCode, setDescription);
        // get int
        testStautsSuccessful(camera->currentUserSet().getEnumValue(parameterName, getModeValue), getCode, getDescription);

        EXPECT_NE(getModeString, modePair.first);
        EXPECT_NE(getModeValue, modePair.second);
        std::cout << "Invalid:    " << getModeString << "  ->  " << modePair.first << std::endl;
        std::cout << "Invalid:    " << getModeValue << "  ->  " << modePair.second << std::endl;

    }

    auto* parameter = camera->currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<EnumParameter*>(parameter);
    if (!parameterValue)
        FAIL();

   
    for (const auto& modePair : setValueList) {
        int getModeValue;
        std::string getModeString;

        // set string
        testStautsSuccessful(parameterValue->setValue(modePair.first), setCode, setDescription);
        // get string
        testStautsSuccessful(parameterValue->getValue(getModeString), getCode, getDescription);
        // set int
        testStautsSuccessful(parameterValue->setValue(modePair.second), setCode, setDescription);
        // get int
        testStautsSuccessful(parameterValue->getValue(getModeValue), getCode, getDescription);

        EXPECT_NE(getModeString, modePair.first);
        EXPECT_NE(getModeValue, modePair.second);

        std::cout << getModeValue << "  ->  " << modePair.second << std::endl;

    }

    std::map<std::string, int> getValueList;
    testStautsSuccessful(parameterValue->getValues(getValueList));
    EXPECT_NE(getValueList, setValueList);
   
}


// Test invalid Enum value
void testInvalidValue(mmind::eye::Camera* camera, const std::string& parameterName, const std::pair<std::string, int>& setValueList,
                                   const int& setCode, const std::string& setDescription,
                                   const int& getCode, const std::string& getDescription,
                                   const bool& otherCameraFlag)
{
    int getModeValue;
    std::string getModeString;
    // set string
    testStautsSuccessful(camera->currentUserSet().setEnumValue(parameterName, setValueList.first), setCode, setDescription);
    // get string
    testStautsSuccessful(camera->currentUserSet().getEnumValue(parameterName, getModeString), getCode, getDescription);
    // set int
    testStautsSuccessful(camera->currentUserSet().setEnumValue(parameterName, setValueList.second), setCode, setDescription);
    // get int
    testStautsSuccessful(camera->currentUserSet().getEnumValue(parameterName, getModeValue), getCode, getDescription);

    EXPECT_NE(getModeString, setValueList.first);
    EXPECT_NE(getModeValue, setValueList.second);
    std::cout << "Invalid:    " << getModeString << "  ->  " << setValueList.first << std::endl;
    std::cout << "Invalid:    " << getModeValue << "  ->  " << setValueList.second << std::endl;


    auto* parameter = camera->currentUserSet().getParameter(parameterName);

    if (!otherCameraFlag)
        EXPECT_FALSE(parameter);
    else {
        if (!parameter)
            FAIL();

        auto* parameterValue = dynamic_cast<EnumParameter*>(parameter);
        if (!parameterValue)
            FAIL();



        // set string
        testStautsSuccessful(parameterValue->setValue(setValueList.first), setCode, setDescription);
        // get string
        testStautsSuccessful(parameterValue->getValue(getModeString), getCode, getDescription);
        // set int
        testStautsSuccessful(parameterValue->setValue(setValueList.second), setCode, setDescription);
        // get int
        testStautsSuccessful(parameterValue->getValue(getModeValue), getCode, getDescription);

        EXPECT_NE(getModeString, setValueList.first);
        EXPECT_NE(getModeValue, setValueList.second);

        std::cout << getModeValue << "  ->  " << setValueList.second << std::endl;
    }
}





/*******************************************************************************************************************
*                                                         Parameter Attribute Test
*******************************************************************************************************************/

void testIntParameterAttribute(Parameter* parameter, const int& step, const int& min, const int& max, const std::string& unit) {
    auto* parameterValue = dynamic_cast<IntParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    int getStep, getMin, getMax;
    std::string getUnit;
    testStautsSuccessful(parameterValue->getStep(getStep));
    testStautsSuccessful(parameterValue->getMin(getMin));
    testStautsSuccessful(parameterValue->getMax(getMax));
    testStautsSuccessful(parameterValue->getUnit(getUnit));

    EXPECT_EQ(getStep, step);
    EXPECT_EQ(getMin, min);
    EXPECT_EQ(getMax, max);
    EXPECT_EQ(getUnit, unit);

}

void testDoubleParameterAttribute(Parameter* parameter, const double& step, const double& min, const double& max, const std::string& unit) {
    auto* parameterValue = dynamic_cast<FloatParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    double getStep, getMin, getMax;
    std::string getUnit;

    testStautsSuccessful(parameterValue->getStep(getStep));
    testStautsSuccessful(parameterValue->getMin(getMin));
    testStautsSuccessful(parameterValue->getMax(getMax));
    testStautsSuccessful(parameterValue->getUnit(getUnit));

    EXPECT_EQ(getStep, step);
    EXPECT_EQ(getMin, min);
    EXPECT_EQ(getMax, max);
    EXPECT_EQ(getUnit, unit);

}

void testEnumParameterAttribute(Parameter* parameter, const int& mapSize, const std::vector<std::string>& modes) {
    auto* parameterValue = dynamic_cast<EnumParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    std::map<std::string, int> valueList;
    testStautsSuccessful(parameterValue->getValues(valueList));
    EXPECT_EQ(valueList.size(), mapSize);
    
    std::vector<std::string> modeVec;
    for (const auto& gPair : valueList) {
        if (std::find(modes.begin(), modes.end(), gPair.first) != modes.end())
            SUCCEED();
        else
            FAIL();
        }
}

void testRoiParameterAttribute(Parameter* parameter, const int& maxWidth, const int& maxHeight) {
    auto* parameterValue = dynamic_cast<RoiParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    Size maxSize;
    testStautsSuccessful(parameterValue->getMaxRoiSize(maxSize));
    EXPECT_EQ(maxSize.width, maxWidth);
    EXPECT_EQ(maxSize.height, maxHeight);
}

void testDoubleArrayParameterAttribute(Parameter* parameter, const double& step, const double& min, const double& max, const std::string& unit) {
    auto* parameterValue = dynamic_cast<FloatArrayParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    double getStep, getMin, getMax;
    std::string getUnit;

    testStautsSuccessful(parameterValue->getStep(getStep));
    testStautsSuccessful(parameterValue->getMin(getMin));
    testStautsSuccessful(parameterValue->getMax(getMax));
    testStautsSuccessful(parameterValue->getUnit(getUnit));

    EXPECT_EQ(getStep, step);
    EXPECT_EQ(getMin, min);
    EXPECT_EQ(getMax, max);
    EXPECT_EQ(getUnit, unit);
}

void testRangeArrayParameterAttribute(Parameter* parameter, const int& step, const int& min, const int& max, const std::string& unit) {
    auto* parameterValue = dynamic_cast<RangeParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    int getStep, getMin, getMax;
    std::string getUnit;

    testStautsSuccessful(parameterValue->getStep(getStep));
    testStautsSuccessful(parameterValue->getMin(getMin));
    testStautsSuccessful(parameterValue->getMax(getMax));
    testStautsSuccessful(parameterValue->getUnit(getUnit));

    EXPECT_EQ(getStep, step);
    EXPECT_EQ(getMin, min);
    EXPECT_EQ(getMax, max);
    EXPECT_EQ(getUnit, unit);
}

Parameter* testParameterAttribute(mmind::eye::Camera* camera, const std::string& parameterName, 
                                                          const Parameter::Type& pType, const int& readFlag, 
                                                          const int& writeFlag)
{

    auto* parameter = camera->currentUserSet().getParameter(parameterName);

    EXPECT_EQ(parameter->name(), parameterName);
    EXPECT_NE(parameter->description(), "");
    EXPECT_EQ(parameter->isReadable(), readFlag);
    EXPECT_EQ(parameter->isWritable(), writeFlag);

    switch (parameter->type())
    {
    case Parameter::Type::_Int:
        EXPECT_EQ(pType, Parameter::Type::_Int);
        break;
    case Parameter::Type::_Float:
        EXPECT_EQ(pType, Parameter::Type::_Float);
        break;
    case Parameter::Type::_Bool:
        EXPECT_EQ(pType, Parameter::Type::_Bool);
        break;
    case Parameter::Type::_Enum:
        EXPECT_EQ(pType, Parameter::Type::_Enum);
        break;
    case Parameter::Type::_Roi:
        EXPECT_EQ(pType, Parameter::Type::_Roi);
        break;
    case Parameter::Type::_Range:
        EXPECT_EQ(pType, Parameter::Type::_Range);
        break;
    case Parameter::Type::_FloatArray:
        EXPECT_EQ(pType, Parameter::Type::_FloatArray);
        break;
    default:
        break;
    }
    return parameter;
}

#pragma once
#include <iostream>
#include <chrono>
#include "gtest/gtest.h"
#include <type_traits>
#include <unordered_map>
#include "area/CameraFixture.h"
#include "ErrorStatus.h"
#include "UserSetManager.h"
#include "area_scan_3d_camera/Camera.h"

using namespace mmind::eye;

/*******************************************************************************************************************
*                                                                Camera type
*******************************************************************************************************************/


//[1] Categorize the types of cameras that can be set
enum class CameraType {
    ProjectorCodingModeCamera,    //  ProjectorCodingMode  camera
    ProjectorPowerLevelCamera,       //  ProjectorPowerLevel camera
    ProjectorAntiflickerCamera,         //  ProjectorAntiflicker  camera
    LaserCamera,                                //  Laser camera
    UHPCamera,                                 //  Uhp Camera
    OtherCamera
};

enum class SpecificCameraType{
    LaserCameras,
    UHPCamera,
    OtherCamera
};

SpecificCameraType getSpecificCameraType(const std::string& input);


enum class ScanHDRExposureType{
    HDR_4_996,
    HDR_01_999
};

ScanHDRExposureType getScanHDRExposureTypeCameraType(const std::string& input);

enum class ProjectorTemperatureType {
    TempereatureOfProjector,
    TempereatureUnknow
};

ProjectorTemperatureType getProjectorTemperatureType(const std::string& input);


//[1]
extern  const std::unordered_map<std::string, CameraType> cameraTypeMap;

//[1]
extern  const std::unordered_map<std::string, CameraType> antiFlickerCameraTypeMap;

//[1]
extern  const std::unordered_map<std::string, CameraType> codingModeCameraTypeMap;


//[1] Check whether it is a UHP or Laser camera
CameraType getCameraType(const std::string& input);


//[1] Determine if a camera is available with ProjectorPowerLevel
CameraType getPowerLevelCameraType(const std::string& input);


//[1] Determine if a camera is available in ProjectorCodingMode
CameraType getCodingModeCameraType(const std::string& input);


//[1] Determine if ProjectorAntiflicker is available for the camera
CameraType getAntiflickerCameraType(const std::string& input);


//[2] Categorize the configurable camera 2D exposure modes
enum class Camera2DExposureMode {
    Exposure2DModeNoFlash,             //  No Flash camera
    Exposure2DALLMode                     //  All exposure 2D mode camera
};


//[2] Categorize the configurable camera 2D exposure modes
Camera2DExposureMode get2DExposureModeCamera(const std::string& input);


//[3] Categorize cameras with the type of 2D exposure time that can be set
enum class Camera2DExposure {
    Exposure42D,              // 4-996/1
    Exposure2DOther       // 0.1-999/0.1
};


//[3] Categorize cameras with the type of 2D exposure time that can be set
Camera2DExposure get2DExposureCameraType(const std::string& input);


//[4] Classify cameras with configurable types of 3D exposure times
enum class Camera3DExposure {
    Exposure43D,             // 4-96����
    Exposure83D,             //  8-96 ����
    Exposure453D,           //  0.1-45����
    Exposure3DOther       // 0.1-99����
};

//[4] Classify cameras with configurable types of 3D exposure times
Camera3DExposure getCamera3DExposureType(const std::string& input);

std::string CurrentTimeToString() ;


/*******************************************************************************************************************
*                                                                Function tool
*******************************************************************************************************************/



void ExpectVectorsAlmostEqual(const std::vector<double>& vec1, const std::vector<double>& vec2, double tolerance);

bool ExpectROIAlmostEqual(const ROI& roi1, const ROI& roi2);

void testStautsSuccessful(const ErrorStatus& status, int code=0, std::string description = "", bool isMatch=true);

void isIncludeUserSet(UserSetManager& usm, const std::string& userSetName, bool flag);


/*******************************************************************************************************************
*                                                                Valid Parameter Test
*******************************************************************************************************************/

// test int value [start value: 0]
void testValue(mmind::eye::Camera* camera, const std::string& parameterName, const int& setValue);

// Test double value  [start value: 0.1]
void testValue(mmind::eye::Camera* camera, const std::string& parameterName, const double& setValue);

// Test bool value  [start value: 0.1]
void testValue(mmind::eye::Camera* camera, const std::string& parameterName, const bool& setValue);

// Test Enum value  
void testValue(mmind::eye::Camera* camera, const std::string& parameterName, const std::map<std::string, int>& setValueList);

// Test Enum value  
void testValue(mmind::eye::Camera* camera, const std::string& parameterName, const std::pair<std::string, int>& modePair);

// Test double array value
void testValue(mmind::eye::Camera* camera, const std::string& parameterName, const double& setValue, const int& repeat);

// Test Range value 
void testValue(mmind::eye::Camera* camera, const std::string& parameterName, const int& setValue, const int& winSize);

// Test ROI value  [start value: 0.1]
void testValue(mmind::eye::Camera* camera, const std::string& parameterName, const ROI& setRoi);


/*******************************************************************************************************************
*                                                             Invalid Parameter Test
*******************************************************************************************************************/


// Test invalid int value
void testInvalidValue(mmind::eye::Camera* camera, const std::string& parameterName, const int& setValue,
                                  const int& setCode, const std::string& setDescription,
                                  const int& getCode, const std::string& getDescription,
                                  const bool& otherCameraFlag = true);


// Test invalid Depth Range value
void testInvalidValue(mmind::eye::Camera* camera, const std::string& parameterName,
                                   const Range<int>& setRange,
                                   const int& setCode, const std::string& setDescription,
                                   const int& getCode, const std::string& getDescription);


// Test invalid double array value
void testInvalidValue(mmind::eye::Camera* camera, const std::string& parameterName, 
                                  const std::vector<double>& setArrayValue, 
                                  const int& setCode, const std::string& setDescription,
                                  const int& getCode, const std::string& getDescription);
 

// Test invalid double value
void testInvalidValue(mmind::eye::Camera* camera, const std::string& parameterName, const double& setValue,
                                   const int& setCode, const std::string& setDescription, 
                                   const int& getCode, const std::string& getDescription);

// Test invalid Roi value
void testInvalidValue(mmind::eye::Camera* camera, const std::string& parameterName,const ROI& setRoi,
                                   const int& setCode, const std::string& setDescription, 
                                   const int& getCode, const std::string& getDescription);

// Test invalid Enum value
void testInvalidValue(mmind::eye::Camera* camera, const std::string& parameterName, const std::map<std::string, int>& setValueList,
                                   const int& setCode,  const std::string& setDescription,
                                   const int& getCode, const std::string& getDescription);


// Test invalid Enum value
void testInvalidValue(mmind::eye::Camera* camera, const std::string& parameterName, const std::pair<std::string, int>& setValueList,
                                   const int& setCode, const std::string& setDescription,
                                   const int& getCode, const std::string& getDescription,
                                   const bool& otherCameraFlag=true);




/*******************************************************************************************************************
*                                                         Parameter Attribute Test
*******************************************************************************************************************/

void testIntParameterAttribute(Parameter* parameter, const int& step, const int& min, const int& max, const std::string& unit = "");

void testDoubleParameterAttribute(Parameter* parameter, const double& step, const double& min, const double& max, const std::string& unit=""); 

void testEnumParameterAttribute(Parameter* parameter, const int& mapSize, const std::vector<std::string>& modes); 

void testRoiParameterAttribute(Parameter* parameter, const int& maxWidth, const int& maxHeight); 

void testDoubleArrayParameterAttribute(Parameter* parameter, const double& step, const double& min, const double& max, const std::string& unit=""); 

void testRangeArrayParameterAttribute(Parameter* parameter, const int& step, const int& min, const int& max, const std::string& unit = ""); 

Parameter* testParameterAttribute(mmind::eye::Camera* camera, const std::string& parameterName, 
                                                          const Parameter::Type& pType, const int& readFlag = 1, 
                                                          const int& writeFlag = 1);

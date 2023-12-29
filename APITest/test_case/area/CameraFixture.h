#pragma once
#include <iostream>
#include <gtest/gtest.h>
#include "CommonTypes.h"
#include "CameraFunction.h"
#include "TestFixture.h"

using namespace mmind::eye;

/**
*      Parameter 2D
*/

class CameraScan2DExposureMode :
	public CameraSDKFixture, public ::testing::WithParamInterface <std::pair<std::string, int>> {
public:
};


class CameraScan2DExposureTime :
	public CameraSDKFixture, public ::testing::WithParamInterface<int> {
};

class CameraScan2DSharpenFactor :
	public CameraSDKFixture, public ::testing::WithParamInterface<int> {
};

class CameraScan2DExpectedGrayValue : 
	public CameraSDKFixture, public ::testing::WithParamInterface<int> {
};

class CameraScan2DToneMappingEnable :
	public CameraSDKFixture, public ::testing::WithParamInterface<bool> {
};

class CameraScan2DROI :
	public CameraSDKFixture, public ::testing::WithParamInterface<int> {
};


class CameraHDRExposureSequence :
	public CameraSDKFixture, public ::testing::WithParamInterface<int> {
};

/**
*      Parameter 3D
*/
class CameraScan3DExposureSequence :
	public CameraSDKFixture, public ::testing::WithParamInterface<int> {
};

class CameraScan3DGain :
	public CameraSDKFixture, public ::testing::WithParamInterface<int> {
};

class CameraDepthRange :
	public CameraSDKFixture, public ::testing::WithParamInterface<int> {
};


class CameraScan3DROI :
	public CameraSDKFixture, public ::testing::WithParamInterface<int> {
};

/**
*     Parameter PointCloud
*/
class CameraParametersPointCloudSurfaceSmoothing :
	public CameraSDKFixture, public  ::testing::WithParamInterface <std::pair<std::string, int>> {
};


class CameraParametersPointCloudNoiseRemoval :
	public CameraSDKFixture, public  ::testing::WithParamInterface <std::pair<std::string, int>> {
};


class CameraParametersPointCloudOutlierRemoval :
	public CameraSDKFixture, public  ::testing::WithParamInterface <std::pair<std::string, int>> {

};

class CameraParametersPointCloudEdgePreservation :
	public CameraSDKFixture, public  ::testing::WithParamInterface <std::pair<std::string, int>> {
};


class CameraParametersPointCloudFringeContrastThreshold :
	public CameraSDKFixture, public ::testing::WithParamInterface<int> {
};

class CameraParametersPointCloudFringeMinThreshold :
	public CameraSDKFixture, public ::testing::WithParamInterface<int> {
};


/**
*     Parameter Laser
*/
class CameraParametersLaserPowerLevel :
	public CameraSDKFixture, public ::testing::WithParamInterface<int> {
};

class CameraParametersLaserFringeCodingMode :
	public CameraSDKFixture, public ::testing::WithParamInterface<std::map<std::string, int>> {
public:
    static  std::vector<std::map<std::string, int>> MapGenerator() {
		std::vector<std::map<std::string, int>> mapCollection;

		std::map<std::string, int> map;
		map["Fast"] = 0;
		map["Accurate"] = 1;
		mapCollection.push_back(map);

        return mapCollection;
    }
};


class CameraParametersLaserFramePartitionCount :
	public CameraSDKFixture, public ::testing::WithParamInterface<int> {
};


/**
*     Parameter UHP
*/
// class CameraParametersUhpFringeCodingMode :
// 	public CameraSDKFixture, public ::testing::WithParamInterface<std::pair<std::string, int>> {
// };



class CameraParametersUhpCaptureMode :
	public CameraSDKFixture, public ::testing::WithParamInterface<std::pair<std::string, int>> {
};


/**
*      Parameter Projector
*/

class CameraParametersProjectorPowerLevel :
	public CameraSDKFixture, public ::testing::WithParamInterface<std::pair<std::string, int>> {
public:
	static  std::vector<std::map<std::string, int>> MapGenerator() {
		std::vector<std::map<std::string, int>> mapCollection;
		std::map<std::string, int> map;
		map["High"] = 0;
		map["Normal"] = 1;
		map["Low"] = 2;

		mapCollection.push_back(map);
		return mapCollection;
	}
};

class CameraParametersProjectorFringeCodingMode :
	public CameraSDKFixture, public ::testing::WithParamInterface<std::pair<std::string, int>> {
public:
	static  std::vector<std::map<std::string, int>> MapGenerator() {
		std::vector<std::map<std::string, int>> mapCollection;
		std::map<std::string, int> map;
		map["Fast"] = 0;
		map["Accurate"] = 1;

		mapCollection.push_back(map);
		return mapCollection;
	}
};

class CameraParametersProjectorAntiFlickerMode :
	public CameraSDKFixture, public ::testing::WithParamInterface<std::pair<std::string, int>> {
public:
	static  std::vector<std::map<std::string, int>> MapGenerator() {
		std::vector<std::map<std::string, int>> mapCollection;
		std::map<std::string, int> map;
		map["Off"] = 0;
		map["AC50Hz"] = 1;
		map["AC60Hz"] = 2;

		mapCollection.push_back(map);
		return mapCollection;
	}
};


/**
*      Parameter Attribute
*/
class CameraAttribute :public CameraSDKFixture {
};

/**
*      UserSetManager
*/
class CameraUserSetsManager :public CameraSDKFixture {
};

/**
*      Message
*/
class CameraMessage :public CameraSDKFixture {
};


/**
*      Invalid UserSetManager
*/
class CameraInvalidUserSetsManager :public CameraSDKFixture {
};



/**
*      Invalid Parameter
*/
// 2D

class CameraInvalidParametersScan2DExposureMode :
	public CameraSDKFixture, public ::testing::WithParamInterface<std::pair<std::string, int>> {
};

class CameraInvalidParametersScan2DExposureTime :
	public CameraSDKFixture, public ::testing::WithParamInterface<double> {
};

class CameraInvalidParametersScan2DROI :
	public CameraSDKFixture, public ::testing::WithParamInterface<ROI> {
};


class CameraInvalidParametersScan2DSharpenFactor :
	public CameraSDKFixture, public ::testing::WithParamInterface<double> {
};

class CameraInvalidParametersScan2DExpectedGrayValue :
	public CameraSDKFixture, public ::testing::WithParamInterface<int> {
};


class CameraInvalidParametersScan2DHDRExposureSequence :
	public CameraSDKFixture, public ::testing::WithParamInterface<std::vector<double>> {
};



// 3D

class CameraInvalidParametersScan3DExposureSequence :
	public CameraSDKFixture, public ::testing::WithParamInterface<std::vector<double>> {
};


class CameraInvalidParametersScan3DGain :
	public CameraSDKFixture, public ::testing::WithParamInterface<double> {
};


class CameraInvalidParametersScan3DDepthRange :
	public CameraSDKFixture, public ::testing::WithParamInterface<Range<int>> {
public:
	static std::vector<Range<int>> invalidRangeGenerator() {
		return {
			{100, 99},
			{100, 100},
			{0, 5001}
		};
	}

};

class CameraInvalidParametersScan3DROI :
	public CameraSDKFixture, public ::testing::WithParamInterface<ROI> {
};


// Invalid Point Cloud
class CameraInvalidParametersPointCloudSurfaceSmoothing :
	public CameraSDKFixture, public ::testing::WithParamInterface<std::pair<std::string, int>> {
};

class CameraInvalidParametersPointCloudNoiseRemoval :
	public CameraSDKFixture, public ::testing::WithParamInterface<std::pair<std::string, int>> {
};

class CameraInvalidParametersPointCloudOutlierRemoval :
	public CameraSDKFixture, public ::testing::WithParamInterface<std::pair<std::string, int>> {
};

class CameraInvalidParametersPointCloudEdgePreservation :
	public CameraSDKFixture, public ::testing::WithParamInterface<std::pair<std::string, int>> {
};

class CameraInvalidParametersPointCloudFringeContrastThreshold :
	public CameraSDKFixture, public ::testing::WithParamInterface<int> {
};

class CameraInvalidParametersPointCloudFringeMinThreshold :
	public CameraSDKFixture, public ::testing::WithParamInterface<int> {
};



// Laser
class CameraInvalidParametersLaserPowerLevel :
	public CameraSDKFixture, public ::testing::WithParamInterface<int> {
};

class CameraInvalidParametersLaserFringeCodingMode :
	public CameraSDKFixture, public ::testing::WithParamInterface<std::pair<std::string, int>> {
};

class CameraInvalidParametersLaserFramePartitionCount :
	public CameraSDKFixture, public ::testing::WithParamInterface<int> {
};



// UHP
// class CameraInvalidParametersUhpFringeCodingMode :
// 	public CameraSDKFixture, public ::testing::WithParamInterface<std::pair<std::string, int>> {
// };

class CameraInvalidParametersUhpCaptureMode :
	public CameraSDKFixture, public ::testing::WithParamInterface<std::pair<std::string, int>> {
};

// Projector
class CameraInvalidParametersProjectorPowerLevel :
	public CameraSDKFixture, public ::testing::WithParamInterface<std::pair<std::string, int>> {
};

class CameraInvalidParametersProjectorFringeCodingMode :
	public CameraSDKFixture, public ::testing::WithParamInterface<std::pair<std::string, int>> {
};

class CameraInvalidParametersProjectorAntiFlickerMode :
	public CameraSDKFixture, public ::testing::WithParamInterface<std::pair<std::string, int>> {
};
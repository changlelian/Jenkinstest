#include <iostream>
#include "area/CameraFixture.h"
#include "area/CameraFunction.h"
#include "gtest/gtest.h"

using namespace mmind::eye;




/**
*  CameraInfo
*/

TEST_F(CameraMessage, CameraInfo) {
	CameraInfo info;
	testStautsSuccessful(gCamPtr->getCameraInfo(info));

	EXPECT_EQ(info.model, modelName);
	EXPECT_NE(info.serialNumber, "");
	EXPECT_NE(info.ipAddress, "");
	EXPECT_NE(info.subnetMask, "");
	EXPECT_EQ(info.port, 5577);
	EXPECT_NE(info.firmwareVersion.toString(), "");
	EXPECT_NE(info.hardwareVersion.toString(), "");

	switch (info.ipAssignmentMethod)
	{
	case mmind::eye::IpAssignmentMethod::Unknown:
		FAIL();
	case mmind::eye::IpAssignmentMethod::DHCP:
		break;
	case mmind::eye::IpAssignmentMethod::Static:
		break;
	case mmind::eye::IpAssignmentMethod::LLA:
		break;
	default:
		break;
	}
}



/**
*  CameraStatus
*/

TEST_F(CameraMessage, CameraStatus) {
	CameraStatus camStatus;
	testStautsSuccessful(gCamPtr->getCameraStatus(camStatus));

	switch (getProjectorTemperatureType(modelName))
	{
	case ProjectorTemperatureType::TempereatureOfProjector:

		EXPECT_NE(camStatus.temperature.projectorTemperature, 0);
		break;;

	default:
		EXPECT_EQ(camStatus.temperature.projectorTemperature, 0);
		break;
	}


}

/**
*  CameraResolution
*/
TEST_F(CameraMessage, CameraResolution) {
	CameraResolutions camResolution;
	testStautsSuccessful(gCamPtr->getCameraResolutions(camResolution));

	EXPECT_NE(camResolution.depth.height, 0);
	EXPECT_NE(camResolution.depth.width, 0);
	EXPECT_NE(camResolution.texture.height, 0);
	EXPECT_NE(camResolution.texture.width, 0);
}

#include <iostream>
#include "gtest/gtest.h"
#include "area/CameraFixture.h"
#include "area/CameraFunction.h"

using namespace mmind::eye;




/**
*  Invalid SelectUserSet
*/

// Select not exist name
TEST_F(CameraInvalidUserSetsManager, SelectExistUserSet) {
	std::string testDescription = "Failed to set config name.";

	auto  usm = gCamPtr->userSetManager();
	testStautsSuccessful(usm.selectUserSet("GoogleTestMechMindNotExist"), -11, testDescription);
}


/**
*  Invalid AddUserSet
*/

// Add default name
TEST_F(CameraInvalidUserSetsManager, AddDefaultUserSet) {
	const std::string testDescription = "Failed to add config name.";

	auto  usm = gCamPtr->userSetManager();
	testStautsSuccessful(usm.addUserSet("default"), -11, testDescription);
}

// Add space name
TEST_F(CameraInvalidUserSetsManager, AddSpaceUserSet) {
	const std::string testDescription = "Input user set name is empty.";
	const std::string addName = "   ";

	auto  usm = gCamPtr->userSetManager();
	testStautsSuccessful(usm.addUserSet(addName),-7, testDescription);
	isIncludeUserSet(usm, addName, true);
}





/**
*  DeleteUserSet
*/

// Delete default
TEST_F(CameraInvalidUserSetsManager, DeleteDefaultUserSet) {
	const std::string testDescription = "Failed to delete config name.";
	const std::string name = "default";

	auto  usm = gCamPtr->userSetManager();
	testStautsSuccessful(usm.deleteUserSet(name), -11, testDescription);
	isIncludeUserSet(usm, name, false);

}

// Delete not exist
TEST_F(CameraInvalidUserSetsManager, DeleteNotExistUserSet) {
	std::string testDescription = "Failed to delete config name.";
	const std::string name = "GoogleTestMechMindNotExist";

	auto  usm = gCamPtr->userSetManager();
	testStautsSuccessful(usm.deleteUserSet(name), -11, testDescription);
}



/**
*  ReNameUserSet
*/

// Rename default name
TEST_F(CameraInvalidUserSetsManager, RenameDefaultUserSet) {
	std::string testDescription = "Failed to rename config group";
	const std::string name = "default";
	const std::string name1 = "RenameSDKNotExist";

	auto  usm = gCamPtr->userSetManager();
	testStautsSuccessful(usm.selectUserSet(name));
	testStautsSuccessful(usm.currentUserSet().rename(name1), -11, testDescription);
	isIncludeUserSet(usm, name, false);
	isIncludeUserSet(usm, name1, true);
}

// Rename name to space
TEST_F(CameraInvalidUserSetsManager, RenameNotExistUserSet) {
	const std::string name1 = " ";

	auto  usm = gCamPtr->userSetManager();
	const std::string name = "K" + CurrentTimeToString();
	testStautsSuccessful(usm.addUserSet(name));
	testStautsSuccessful(usm.selectUserSet(name));
	testStautsSuccessful(usm.currentUserSet().rename(name1), -7, ErrorDescriptions::InvalidEmptyUserSet);
	usm.deleteUserSet(name);
	isIncludeUserSet(usm, name1, true);
}

// Rename name to default
TEST_F(CameraInvalidUserSetsManager, RenameToExistUserSet) {
	std::string testDescription = "Failed to rename config group";
	const std::string name1 = "default";

	auto  usm = gCamPtr->userSetManager();

	const std::string name = "T" + CurrentTimeToString();
	testStautsSuccessful(usm.addUserSet(name));
	testStautsSuccessful(usm.selectUserSet(name));
	testStautsSuccessful(usm.currentUserSet().rename("default"), -11, testDescription);
	usm.deleteUserSet(name);

	isIncludeUserSet(usm, name1, false);
}

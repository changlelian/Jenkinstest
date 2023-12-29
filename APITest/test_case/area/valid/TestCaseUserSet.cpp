#include <iostream>
#include "gtest/gtest.h"
#include "area/CameraFixture.h"
#include "area/CameraFunction.h"

using namespace mmind::eye;




/**
*  SelectUserSet
*/

TEST_F(CameraUserSetsManager, SelectUserSet) {
	std::vector<std::string> useSets;

	auto  usm = gCamPtr->userSetManager();
	testStautsSuccessful(usm.getAllUserSetNames(useSets));

	for (auto const& name : useSets) {
		std::string userSetName;

		testStautsSuccessful(usm.selectUserSet(name));
		testStautsSuccessful(usm.currentUserSet().getName(userSetName));
		std::cout << name << "  ->  " << userSetName << std::endl;
		EXPECT_EQ(name, userSetName);
	}
}


/**
*  AddUserSet
*/
TEST_F(CameraUserSetsManager, AddUserSet) {
	std::vector<std::string> userSets;
	std::string newUserSet = CurrentTimeToString();
	std::cout << newUserSet << std::endl;

	auto  usm = gCamPtr->userSetManager();
	testStautsSuccessful(usm.addUserSet(newUserSet));
	testStautsSuccessful(usm.getAllUserSetNames(userSets));

	if (std::find(userSets.begin(), userSets.end(), newUserSet) == userSets.end())
		FAIL();

	testStautsSuccessful(usm.deleteUserSet(newUserSet));
}


/**
*  DeleteUserSet
*/
TEST_F(CameraUserSetsManager, DeleteUserSet) {
	std::vector<std::string> userSets;
	std::string newUserSet =  CurrentTimeToString();

	auto  usm = gCamPtr->userSetManager();
	testStautsSuccessful(usm.addUserSet(newUserSet));
	testStautsSuccessful(usm.getAllUserSetNames(userSets));

	if (std::find(userSets.begin(), userSets.end(), newUserSet) == userSets.end())
		FAIL();

	testStautsSuccessful(usm.deleteUserSet(newUserSet));
	testStautsSuccessful(usm.getAllUserSetNames(userSets));

	if (std::find(userSets.begin(), userSets.end(), newUserSet) != userSets.end())
		FAIL();
}

/**
*  ReNameUserSet
*/
TEST_F(CameraUserSetsManager, RenameUserSet) {
	std::vector<std::string> userSets;
	std::string UserName = "AutoTestRename";
	std::string NewUserName = "GTesting";
	
	auto  usm = gCamPtr->userSetManager();
	usm.deleteUserSet(NewUserName);
	testStautsSuccessful(usm.addUserSet(UserName));
	testStautsSuccessful(usm.selectUserSet(UserName));
	testStautsSuccessful(usm.currentUserSet().rename(NewUserName));
	testStautsSuccessful(usm.getAllUserSetNames(userSets));

	if (std::find(userSets.begin(), userSets.end(), NewUserName) == userSets.end())
		FAIL();

	if (std::find(userSets.begin(), userSets.end(), UserName) != userSets.end())
		FAIL();

	testStautsSuccessful(usm.deleteUserSet(NewUserName));

}

#include <iostream>
#include "gtest/gtest.h"
#include "TestFixture.h"
#include "profiler/Profiler.h"
#include "area_scan_3d_camera/Camera.h"


using namespace mmind::eye;

void massage(){
    std::cout << "=================================================================================================================="<< std::endl
              << "MechEyeAPI automated testing based on the googleTest framework, supports testing the MechMind Camera series, usage:" << std::endl
              << "TestMechMindSDK.exe [--gtest_filter] [--gtest_output](option) [--ip] " << std::endl
              << std::endl << "For example: "<< std::endl
              << "TestMechMindSDK.exe --gtest_filter=*Camera*  --ip=192.168.20.184"<< std::endl << std::endl
              << "If you want to generate test report, for example: " << std::endl
              << "TestMechMindSDK.exe --gtest_filter=*Camera*  --gtest_output=xml:your_report.xml --ip=192.168.20.184" << std::endl
              << "=================================================================================================================="<< std::endl;
}               


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << argc;
    std::string ip;
    if (argc == 1 || argc != 2){
        massage();
        return -1;
    }

    std::string arg = argv[1];
    if (arg.size() < 12 || arg.substr(0, 5) != "--ip=") { 
        if (arg == "--help")
            return 0;
        std::cout << "Invalid Input" << std::endl;
        return -1;
    }
    

    ip = arg.substr(5); 


    // std::cout << ip;
    mmind::eye::Camera camera;
    auto cameraStatus = camera.connect(ip);

    mmind::eye::Profiler profiler;
    auto profilerStatus = profiler.connect(ip); 

    if (cameraStatus.isOK()) {
        mmind::eye::CameraInfo info;
        camera.getCameraInfo(info);
        std::cout << "Connect to " << info.model << " successful! " << std::endl;

        CameraSDKFixture::setCameraObject(&camera);
        ::testing::GTEST_FLAG(filter) = "Camera*";

    }
    else if (profilerStatus.isOK()) {
        ProfilerSDKFixture::setProfilerObject(&profiler);
        ::testing::GTEST_FLAG(filter) = "*Profiler*";
    }
    else {
        std::cout << "Fail to connect Mech-Eye 3D camera" << std::endl;
        return 0;
    }

    return RUN_ALL_TESTS();
}




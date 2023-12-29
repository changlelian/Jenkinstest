cmake_minimum_required(VERSION 3.10) 

project(TestMechMindSDK)

set(MIN_EYE_VERSION 2.2.0)

add_executable(TestMechMindSDK
    GoogleTestMechMindSDK.cpp
    test_case/TestFixture.cpp
    test_case/area/CameraFunction.cpp
    test_case/profiler/ProfilerFunction.cpp

    test_case/area/invalid/TestCaseInvalidUserSet.cpp
    test_case/area/invalid/parameter/TestCaseInvalid2d.cpp
    test_case/area/invalid/parameter/TestCaseInvalid3d.cpp
    test_case/area/invalid/parameter/TestCaseInvalidPointCloud.cpp
    test_case/area/invalid/parameter/TestCaseInvalidLaser.cpp
    test_case/area/invalid/parameter/TestCaseInvalidProjector.cpp
    test_case/area/invalid/parameter/TestCaseInvalidUHP.cpp

    test_case/area/valid/TestCaseUserSet.cpp
    test_case/area/valid/TestCaseMessage.cpp
    test_case/area/valid/parameter/TestCase2d.cpp
    test_case/area/valid/parameter/TestCase3d.cpp
    test_case/area/valid/parameter/TestCasePointCloud.cpp
    test_case/area/valid/parameter/TestCaseLaser.cpp
    test_case/area/valid/parameter/TestCaseUHP.cpp
    test_case/area/valid/parameter/TestCaseProjector.cpp
    test_case/area/valid/parameter/TestParameterAttribute.cpp

    test_case/profiler/valid/parameter/TestCaseScan.cpp
    test_case/profiler/valid/parameter/TestCaseRawImageParameters.cpp
    test_case/profiler/valid/parameter/TestCaseProfileExtractionParameters.cpp
    test_case/profiler/valid/parameter/TestCaseProfileProcessingParameters.cpp
)



target_include_directories(TestMechMindSDK PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/test_case
)

set(DEBUG_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/debug)
set(RELEASE_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/release)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_link_directories(TestMechMindSDK PRIVATE ${DEBUG_LIB_DIR})
    target_compile_definitions(TestMechMindSDK PRIVATE _ITERATOR_DEBUG_LEVEL=2)

    if (WIN32)
        target_compile_options(TestMechMindSDK PRIVATE "/MDd")
        find_package(MechEyeApi ${MIN_EYE_VERSION} REQUIRED CONFIG PATHS "$ENV{MECHEYE_DIR}/API")
        if(NOT MechEyeApi_FOUND)
            message(FATAL_ERROR "MechEyeApi not found. Please install MechEyeApi with version ${MIN_EYE_VERSION} or higher.")
        endif()

        # 添加mecheye lib_debug文件的搜索路径
        target_link_directories(TestMechMindSDK PRIVATE "$ENV{MECHEYE_DIR}/API/lib_debug")
        target_link_libraries(TestMechMindSDK PRIVATE MechEyeApid)
    
    else()
        find_package(Threads REQUIRED)
        target_link_libraries(TestMechMindSDK PRIVATE Threads::Threads)
        target_compile_options(TestMechMindSDK PRIVATE -g)
    endif()
else()
    target_link_directories(TestMechMindSDK PRIVATE ${RELEASE_LIB_DIR})
    target_compile_definitions(TestMechMindSDK PRIVATE _ITERATOR_DEBUG_LEVEL=0)

    if (WIN32)
        target_compile_options(TestMechMindSDK PRIVATE "/MD")
        find_package(MechEyeApi ${MIN_EYE_VERSION} REQUIRED CONFIG PATHS "$ENV{MECHEYE_DIR}/API")
        if(NOT MechEyeApi_FOUND)
            message(FATAL_ERROR "MechEyeApi not found. Please install MechEyeApi with version ${MIN_EYE_VERSION} or higher.")
        endif()
        target_compile_options(TestMechMindSDK PRIVATE /MD)

        target_link_directories(TestMechMindSDK PRIVATE "$ENV{MECHEYE_DIR}/API/lib")
        target_link_libraries(TestMechMindSDK PRIVATE MechEyeApi)
    else()
        find_package(Threads REQUIRED)
        target_link_libraries(TestMechMindSDK PRIVATE Threads::Threads)
        target_compile_options(TestMechMindSDK PRIVATE -O3)

        # ubuntu下查找MechEye库
        find_package(PkgConfig)
        if(NOT PkgConfig_FOUND)
            message(FATAL_ERROR "PkgConfig not found.")
        else()
            pkg_check_modules(MECHEYEAPI REQUIRED MechEyeApi)
            if(NOT MECHEYEAPI_FOUND)
                message(FATAL_ERROR "MechEyeApi not found. Please install MechEyeApi first.")
            endif()
        endif()
    endif()
endif()

include_directories(${MECHEYEAPI_INCLUDE_DIRS})
link_directories(${MECHEYEAPI_LIBRARY_DIRS})
target_link_libraries(TestMechMindSDK PRIVATE MechEyeApi gtest gmock)

# add_custom_target(run_tests ALL COMMAND MyProject)

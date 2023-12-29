#!/bin/sh


dpkg -P MechEyeApi


rm -rf /opt/mech-mind


dpkg -i /home/MechEye*_amd64.deb

# sample path 
samples_path=/opt/mech-mind/mech-eye-sdk/samples/cpp/

build_projects="
    area_scan_3d_camera/Util/GetCameraIntrinsics
    area_scan_3d_camera/Util/ManageUserSets
    area_scan_3d_camera/Util/PrintCameraInfo
    area_scan_3d_camera/Util/SaveAndLoadUserSet
    area_scan_3d_camera/Util/SetDepthRange
    area_scan_3d_camera/Util/SetScanningParameters
    area_scan_3d_camera/Util/SetPointCloudProcessingParameters
    area_scan_3d_camera/Pcl/ConvertPointCloudWithNormalsToPcl
    area_scan_3d_camera/Pcl/ConvertPointCloudToPcl
    area_scan_3d_camera/Advanced/MultipleCamerasCaptureSequentially
    area_scan_3d_camera/Calibration/HandEyeCalibration
    area_scan_3d_camera/Advanced/MultipleCamerasCaptureSimultaneously
    area_scan_3d_camera/Advanced/SetParametersOfUHPCameras
    area_scan_3d_camera/Advanced/SetParametersOfLaserCameras
    area_scan_3d_camera/Advanced/CapturePeriodically
    area_scan_3d_camera/Advanced/ConvertDepthMapToPointCloud
    area_scan_3d_camera/Advanced/Mapping2DImageToDepthMap
    area_scan_3d_camera/Advanced/RegisterCameraEvent
    area_scan_3d_camera/Basic/CapturePointCloudWithNormals
    area_scan_3d_camera/Basic/CapturePointCloud
    area_scan_3d_camera/Basic/CaptureDepthMap
    area_scan_3d_camera/Basic/ConnectAndCaptureImages
    area_scan_3d_camera/Basic/CapturePointCloudHDR
    area_scan_3d_camera/Basic/ConnectToCamera
    area_scan_3d_camera/Basic/Capture2DImage
    profiler/AcquirePointCloud
    profiler/AcquireProfileData
    profiler/RegisterProfilerEvent
    profiler/AcquireProfileDataUsingCallback
    profiler/ManageUserSets
"

# open the samples path 
cd "$samples_path" || exit 1

# build single samples
for project in $build_projects; do
    project_path="${samples_path}${project}"
    
    # enter the project directory
    cd "$project_path" || exit 1
    
    # build
    eval "mkdir -p build && cd build && cmake .. && make"
    
    # execute status
    if [ $? -ne 0 ]; then
        exit 1
    fi

    # Move back to the samples path before the next iteration
    cd "$samples_path" || exit 1
done

exit 0


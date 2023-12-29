

# MechEyeAPI自动化测试工程 (2.2.0)

---
# 目录
[TOC]


---


## 1. 功能介绍

> &nbsp;
>[1]&nbsp; 本测试工程基于C++ GoogleTest框架编写，旨在测试 `新版本C++API` 。
>
>[2]&nbsp; 通过对不同型号相机的参数进行区分，有针对性的遍历的参数涵盖各相机的`正常值、边界值、异常值`。
>
>[3]&nbsp; 测试人员可根据实际需求选择是否生成`测试报告`。
>&nbsp;

---

## 2. 使用须知
1）使用前 **务必** 安装对应平台（Linux/Windows）MechEye-viewer SDK 安装包.
2）测试使用的环境为windows10/11, Linux-X64(Ubuntu20) 其他场景未经验证.

---

## 3. 使用方法
### 3.1 帮助选项
> 
``` bash
TestMechMindSDK.exe --help   # windows
./TestMechMindSDK   --help   # Linux
```


### 3.2 启动工程 

``` bash
TestMechMindSDK.exe  --gtest_filter=[xxx]  --gtest_output=[xxx](可选) --ip==[xxx.xxx.xxx.xxx]   # windows
./TestMechMindSDK  --gtest_filter=[xxx]  --gtest_output=[xxx](可选) --ip==[xxx.xxx.xxx.xxx]       # Linux
```


**启动工程示例1：**
- 测试IP为 `192.168.20.184` 结构光相机所有测试项。
- 不生成测试报告。

``` bash
TestMechMindSDK.exe --gtest_filter=*Camera*  --ip=192.168.20.184    # windows
./TestMechMindSDK   --gtest_filter=*Camera*  --ip=192.168.20.184    # Linux
```
&nbsp;

**启动工程示例2：**
- 测试IP为 `192.168.20.184` 结构光相机`ProjectorPowerLevel`测试项。
- 生成测试报告，存放于 `C:\build`文件夹中。

``` bash
TestMechMindSDK.exe --gtest_filter=*Camera*  --gtest_output=xml:C:\build.xml --ip=192.168.20.184    # windows
./TestMechMindSDK   --gtest_filter=*Camera*  --gtest_output=xml:C:\build.xml  --ip=192.168.20.184    # Linux
```



---



## 4.测试相机
| 类型| 名称 | 是否验证 |
|--|--|--|
|结构光| Laser L          |  √|
|结构光|Laser L Enhanced  |  |
|结构光| UHP-140          |  √|
|结构光| NANO             |  √|
|结构光| PRO S            |  √|
|结构光| Log M            |  √|
|结构光| Pro L Enhanced   |  |
|结构光| Pro M Enhanecd   |  |
|结构光| DEEP             |  √|
|结构光| Deep             |  √|
|结构光| LSR L            |  √|
|结构光| PRO XS           | √ |
|结构光| NANO             | √ |
|轮廓扫描仪| LNX 8030             |  |
|轮廓扫描仪| LNX 8080             |  |
|轮廓扫描仪| LNX 8300             |  |


---
 

## 5. 测试覆盖
### 5.1 结构光
| **【有效】测试项** | **是否完成** | **【无效】测试项** | **是否完成** |
| --- | --- | --- | --- |
| 2D系列参数 | √ | 2D系列参数 | √ |
| 3D系列参数 | √ | 3D系列参数 | √ |
| 点云系列参数 | √ | 点云系列参数 | √ |
| 激光系列参数 | √ | 激光系列参数 | √ |
| UHP系列参数 |√ | UHP系列参数 | √ |
| Projector系列参数 | √ | Projector系列参数 | √ |
| 参数组系列 | √ | 参数组系列 | √ |
| 硬编码参数属性 | √ | 相机信息 | √ |
| 相机信息 | √ | 相机状态 | √ |
| 相机状态 | √ | 相机分辨率 | √ |
| 相机分辨率 | √ | 断连采图 |  |
| 状态码/描述 | √ | 状态码/描述 | √|
| 有效拷贝 |  | 无效拷贝 |  |
| 相机状态监测 | |  |  |
| 采图测试（高） |  | |  |
| 场景测试 |  |  |  |


---

## 6.用例过滤
- *Camera*：过滤结构光用例
  -  *CameraParameter*：过滤所有参数用例
  -  *CameraScan2D*：过滤2D系列用例
  -  *CameraScan3D*：过滤3D系列用例
  -  *CameraParameterLaser*：过滤Laser系列用例
  -   *CameraParameterPointCloud*：过滤PointCloud系列用例
  -  *CameraParametersUhp*：过滤UHP系列用例
  -  *CameraParametersProjector*：过滤Projector系列用例
-  *CameraInvalid*：过滤所有无效用例
     -   *CameraParametersProjector*：过滤无效Projector系列用例
     -  *CameraInvalidParametersUhp*：过滤无效uhp系列用例
     -  *CameraInvalidParametersLaser*：过滤无效Laser系列用例
     -  *CameraInvalidParametersScan3D*：过滤无效3D系列用例
     -   *CameraInvalidParametersScan2D*：过滤无效2D系列用例
     -   *CameraInvalidParametersPointCloud*：过滤无效PointCloud系列用例
     -  *CameraInvalidUserSets*：过滤无效UserSets系列用例
-  *CameraAttribute*：过滤所有硬编码用例
- *CameraMessage*：过滤所有相机信息/状态用例

---
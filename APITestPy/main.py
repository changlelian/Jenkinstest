import os
import sys
import time
import unittest
from area import *
from BeautifulReport import BeautifulReport
from mecheye.area_scan_3d_camera import *
from mecheye.profiler_utils import *


if __name__ == '__main__':
    if len(sys.argv) != 2:
        raise Exception("错误：请输入正确的启动命令，例如：python [python文件] [相机IP]")
    os.environ['IP_INFO'] = sys.argv.pop(1)
    ip_info = os.environ.get('IP_INFO')

    camera = Camera()
    profiler = Profiler()
    test_loader = unittest.TestLoader()

    camera_connect_status = camera.connect(ip_info, 1000000)
    profiler_connect_status = profiler.connect(ip_info, 1000000)

    test_case_vector = []
    if camera_connect_status.is_ok():
        test_suite1 = test_loader.discover('area', pattern='test_case*.py')
        # test_suite2 = test_loader.discover('area/capture', pattern='test_case*.py')
        test_suite3 = test_loader.discover('area/parameter', pattern='test_case*.py')
        test_case_vector.append(test_suite1)
        # test_case_vector.append(test_suite2)
        test_case_vector.append(test_suite3)

    elif profiler_connect_status.is_ok():
        test_suite1 = test_loader.discover('profiler', pattern='test_case*.py')
        test_suite2 = test_loader.discover('profiler/capture', pattern='test_case*.py')
        test_suite3 = test_loader.discover('profiler/parameter', pattern='test_case*.py')
        test_case_vector.append(test_suite1)
        test_case_vector.append(test_suite2)
        test_case_vector.append(test_suite3)

    combined_test_suite = unittest.TestSuite(test_case_vector)

    cur_time = time.strftime('%Y-%m-%d_%H-%M-%S', time.localtime(time.time()))
    file_name = 'MechEyeAPI_{}_自动化测试报告{}'.format(str(ip_info), str(cur_time))

    result = BeautifulReport(combined_test_suite)
    result.report(filename=file_name,
                  description='MechEyeAPI结构光相机自动化测试报告',
                  report_dir='./report', theme='theme_default')



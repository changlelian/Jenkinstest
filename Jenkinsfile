// pipeline {
//     agent any
//     stages {
//         stage('Parallel Stages') {
//             parallel {
//                 stage('Build cpp amd64 samples') {
//                     steps {
//                         script {
//                             sh 'sudo docker run -d -t -v /home/MechMindSDK:/home --name APIBuildTest mecheyeenvimage'
//                             sh 'sudo docker start APIBuildTest'
//                             sh 'sudo docker exec APIBuildTest git clone https://github.com/changlelian/Jenkinstest.git'
//                             sh 'sudo docker exec APIBuildTest echo "裹裹大牛"'
//                             sh 'sudo docker exec APIBuildTest sh /Jenkinstest/ubuntu_build.sh'

//                             sh 'sudo docker stop APIBuildTest'
//                             sh 'sudo docker rm APIBuildTest'
//                         }
//                     }
//                 }

//                 stage('Test cpp camera interface in linux') {
//                     steps {
//                         script {
//                             sh 'sudo docker run -d -t -v /home/MechMindSDK:/home --name APITestCameraInterface mecheyeenvimage'
//                             sh 'sudo docker start APITestCameraInterface'
//                             sh 'sudo docker exec APITestCameraInterface git clone https://github.com/changlelian/Jenkinstest.git'

//                             sh 'sudo docker exec APITestCameraInterface sh /Jenkinstest/APITest/installer.sh'
//                             sh 'sudo docker exec APITestCameraInterface mkdir -p /Jenkinstest/APITest/build'
//                             sh 'sudo docker exec APITestCameraInterface cmake -S /Jenkinstest/APITest -B /Jenkinstest/APITest/build'
//                             sh 'sudo docker exec APITestCameraInterface make -C /Jenkinstest/APITest/build'
//                             sh 'sudo docker exec APITestCameraInterface /Jenkinstest/APITest/build/TestMechMindSDK --gtest_filter=*Camera* --ip=192.168.20.173'
//                             sh 'echo "裹裹小牛hao"'

//                             sh 'sudo docker stop APITestCameraInterface'
//                             sh 'sudo docker rm APITestCameraInterface'
//                         }
//                     }
//                 }

//                 stage('Test cpp profiler interface in linux') {
//                     steps {
//                         script {
//                             sh 'sudo docker run -d -t -v /home/MechMindSDK:/home --name APITestProfilerInterface mecheyeenvimage'
//                             sh 'sudo docker start APITestProfilerInterface'
//                             sh 'sudo docker exec APITestProfilerInterface git clone https://github.com/changlelian/Jenkinstest.git'

//                             sh 'sudo docker exec APITestProfilerInterface sh /Jenkinstest/APITest/installer.sh'
//                             sh 'sudo docker exec APITestProfilerInterface mkdir -p /Jenkinstest/APITest/build'
//                             sh 'sudo docker exec APITestProfilerInterface cmake -S /Jenkinstest/APITest -B /Jenkinstest/APITest/build'
//                             sh 'sudo docker exec APITestProfilerInterface make -C /Jenkinstest/APITest/build'
//                             sh 'sudo docker exec APITestProfilerInterface /Jenkinstest/APITest/build/TestMechMindSDK --gtest_filter=*Profiler* --ip=192.168.20.254'
//                             sh 'echo "裹裹小牛hao"'

//                             sh 'sudo docker stop APITestProfilerInterface'
//                             sh 'sudo docker rm APITestProfilerInterface'
//                         }
//                     }
//                 }

//                 // stage('Test python camera interface in linux') {
//                 //     steps {
//                 //         script {
//                 //             sh 'sudo docker run -d -t -v /home/MechMindSDK:/home --name APITestPythonCameraInterface mecheyeenvimage'
//                 //             sh 'sudo docker start APITestPythonCameraInterface'
//                 //             sh 'sudo docker exec APITestPythonCameraInterface git clone https://github.com/changlelian/Jenkinstest.git'
//                 //             sh 'sudo docker exec APITestPythonCameraInterface python3 -m pip install --upgrade pip -i https://pypi.tuna.tsinghua.edu.cn/simple'

//                 //             // sh 'sudo docker exec APITestPythonCameraInterface sh /Jenkinstest/APITestPy/installer.sh'
//                 //             // sh 'sudo docker exec APITestPythonCameraInterface python3 -m pip install /home/*38*.whl -i https://pypi.tuna.tsinghua.edu.cn/simple'
//                 //             sh 'sudo docker exec APITestPythonCameraInterface python3 -m pip install -r /Jenkinstest/APITestPy/requirements.txt -i https://pypi.tuna.tsinghua.edu.cn/simple'
//                 //             sh 'sudo docker exec APITestPythonCameraInterface python3 /Jenkinstest/APITestPy/main.py 192.168.20.7'

//                 //             sh 'sudo docker stop APITestPythonCameraInterface'
//                 //             sh 'sudo docker rm APITestPythonCameraInterface'
//                 //         }
//                 //     }
//                 // }
//             }
//         }

//         stage('Release Environment'){
//             steps{
//                     sh 'echo "裹裹小二牛hao"'
//             }
//         }
//     }
// }


pipeline {
    agent any
    stages {
        stage('Clone test code'){
            steps{
                sh 'git clone https://github.com/changlelian/Jenkinstest.git /home/mech_mind_sdk/MechMindSDK/GithubTestCode'
            }
        }

        stage('Parallel execute Stages') {
            parallel {
                stage('Build cpp amd64 samples') {
                    steps {
                        script {
                            sh 'sudo docker run -d -t -v /home/mech_mind_sdk/MechMindSDK:/home --name APIBuildTest mecheyeenvimage'
                            sh 'sudo docker start APIBuildTest'
                            sh 'sudo docker exec APIBuildTest sh /home/GithubTestCode/ubuntu_build.sh'
                            sh 'sudo docker stop APIBuildTest'
                            sh 'sudo docker rm APIBuildTest'
                        }
                    }
                }
            }
        }

    }
}
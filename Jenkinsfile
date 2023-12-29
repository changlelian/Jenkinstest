// pipeline {
//     agent any
//     stages{
//         stage('build docker container'){
//             steps {
//                 sh 'sudo docker run -d -t -v /home/MechMindSDK:/home --name APITest mecheyeenvimage'
//                 sh 'sudo docker start APITest'
//             }
//         }

//         stage('clone test code') {
//             steps {
//                 sh 'sudo docker exec APITest git clone https://github.com/changlelian/Jenkinstest.git'
//                 // sh 'cd /home/Jenkinstest'
//                 sh 'sudo docker exec APITest echo "裹裹牛"'
//             }
//         }

//         stage('execute test commands'){
//             steps {
//                 sh 'sudo docker exec APITest sh /Jenkinstest/ubuntu_build.sh'
//             }
//         }

//         stage('docker release'){
//             steps {
//                 sh 'sudo docker stop APITest'
//                 sh 'sudo docker rm APITest'
//             }
//         }

//     }
// }


pipeline {
    agent any
    stages {
        stage('Parallel Stages') {
            parallel {
                // stage('Build cpp amd64 samples') {
                //     steps {
                //         script {
                //             sh 'sudo docker run -d -t -v /home/MechMindSDK:/home --name APITest mecheyeenvimage'
                //             sh 'sudo docker start APITest'
                //             sh 'sudo docker exec APITest git clone https://github.com/changlelian/Jenkinstest.git'
                //             sh 'sudo docker exec APITest echo "裹裹大牛"'
                //             sh 'sudo docker exec APITest sh /Jenkinstest/ubuntu_build.sh'

                //             sh 'sudo docker stop APITest'
                //             sh 'sudo docker rm APITest'
                //         }
                //     }
                // }
                stage('Test cpp interface in linux') {
                    steps {
                        script {
                            sh 'sudo docker run -d -t -v /home/MechMindSDK:/home --name APITestInterface mecheyeenvimage'
                            sh 'sudo docker start APITestInterface'
                            sh 'sudo docker exec APITestInterface git clone https://github.com/changlelian/Jenkinstest.git'
                            sh 'sudo docker exec APITestInterface sh mkdir -p /Jenkinstest/APITest/build'
                            sh 'sudo docker exec APITestInterface sh cmake /Jenkinstest/APITest/build/..'
                            sh 'sudo docker exec make'
                            sh 'echo "裹裹小牛hao"'
                        }
                    }
                }
            }
        }

        stage('Release Environment'){
            steps{
                    sh 'echo "裹裹小二牛hao"'

            }
        }
    }
}

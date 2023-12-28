pipeline {
    agent any
    stages{

        stage('build docker container'){
            steps {
                sh 'sudo docker run -d -t -v /home/MechMindSDK:/home --name APITest mecheyeenvimage'
                sh 'sudo docker start APITest'
            }
        }

        stage('clone test code') {
            steps {
                sh 'docker exec APITest git clone https://github.com/changlelian/Jenkinstest.git' // 切换到自定义工作目录
                sh 'echo "裹裹牛"'
            }
        }

        stage('execute test commands'){
            steps {
                sh 'sudo docker exec APITest sh /home/new_ubuntu_build.sh'
            }
        }

        stage('docker release'){
            steps {
                sh 'sudo docker stop APITest'
                sh 'sudo docker rm APITest'
            }
        }

    }
}


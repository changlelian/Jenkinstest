pipeline {
    agent any
    stages{
        stage('clone test code') {
            steps {
                sh 'cd /var/lib/jenkins/workspace/' // 切换到自定义工作目录
                sh 'python3 MyJenkinsTest/name.py' // 在自定义工作目录中执行构建步骤
            }
        }

        stage('docker container'){
            steps {
                sh 'sudo docker run -d -t -v /home/MechMindSDK:/home --name APITest mecheyeenvimage'
                sh 'sudo docker start APITest'
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


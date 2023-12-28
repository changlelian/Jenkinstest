pipeline {
    agent any
    stages{

        stage('docker container'){
            steps {
                sh 'docker run -v /home/MechMindSDK:/home --name APITest mecheyeenvimage'
                sh 'python3 MyJenkinsTest/name.py' // 在自定义工作目录中执行构建步骤
            }
        }

        stage('execute commands'){
            steps {
                sh 'docker exec APITest echo Hello from inside Docker container'
            }
        }

        stage('clone test code') {
            steps {
                sh 'cd /var/jenkins_home/workspace/' // 切换到自定义工作目录
                sh 'python3 MyJenkinsTest/name.py' // 在自定义工作目录中执行构建步骤
            }
        }


    }
}


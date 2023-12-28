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
                sh 'sudo docker rm APITest'
                sh 'sudo docker run -it -v /home/MechMindSDK:/home --name APITest mecheyeenvimage'
                sh 'sudo docker mecheyeenvimage'
            }
        }

        stage('execute commands'){
            steps {
                sh 'sudo docker exec APITest echo Hello from inside Docker container'
            }
        }




    }
}


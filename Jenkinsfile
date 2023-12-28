pipeline {
    agent any
    stages{

        stage('docker container'){
            steps {
                sh 'echo "mechmind" | sudo -S docker run -v /home/MechMindSDK:/home --name APITest mecheyeenvimage'
            }
        }

        stage('execute commands'){
            steps {
                sh 'sudo docker exec APITest echo Hello from inside Docker container'
            }
        }

        stage('clone test code') {
            steps {
                sh 'cd /var/lib/jenkins/workspace/' // 切换到自定义工作目录
                sh 'python3 MyJenkinsTest/name.py' // 在自定义工作目录中执行构建步骤
            }
        }


    }
}


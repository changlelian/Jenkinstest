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
                sh 'sudo docker exec APITest git clone https://github.com/changlelian/Jenkinstest.git'
                // sh 'cd /home/Jenkinstest'
                sh 'sudo docker exec APITest echo "裹裹牛"'
            }
        }

        stage('execute test commands'){
            steps {
                sh 'sudo docker exec APITest sh /Jenkinstest/MyJenkinsTest/ubuntu_build.sh'
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


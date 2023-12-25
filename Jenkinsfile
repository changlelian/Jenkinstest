pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                sh 'cd /var/jenkins_home/workspace/' // 切换到自定义工作目录
                sh 'python3 TESTAPI_main/MyJenkinsTest/name.py' // 在自定义工作目录中执行构建步骤
            }
        }
    }
}



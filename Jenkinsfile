pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                sh 'cd /var/jenkins_mount/workspace/TESTAPI_main' // 切换到自定义工作目录
                sh 'python3 MyJenkinsTest\\name.py' // 在自定义工作目录中执行构建步骤
            }
        }
    }
}



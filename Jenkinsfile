pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                bat 'cd /var/jenkins_home/Jenkins_workspace' // 切换到自定义工作目录
                bat 'python3 MyJenkinsTest\\name.py' // 在自定义工作目录中执行构建步骤
            }
        }
    }
}

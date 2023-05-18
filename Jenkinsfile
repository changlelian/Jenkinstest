pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                bat 'cd E:\\Jenkins_workspace' // 切换到自定义工作目录
                bat 'python MyJenkinsTest\\name.py' // 在自定义工作目录中执行构建步骤
            }
        }
    }
}

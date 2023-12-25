pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                sh 'cd /home/mech_mind_sdk/JenkinsTestMMind' // 切换到自定义工作目录
                sh 'python3 MyJenkinsTest\\name.py' // 在自定义工作目录中执行构建步骤
            }
        }
    }
}

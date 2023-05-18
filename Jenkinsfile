pipeline {
    agent {
        node {
            label 'windows' // 指定Jenkins中配置的Windows节点的标签
        }
    }
    stages {
        stage('build') {
            steps {
                bat 'python --version' // 使用bat命令来运行Python脚本，适用于Windows系统
            }
        }
    }
}

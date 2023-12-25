// pipeline {
//     agent any
//     stages {
//         stage('Build') {
//             steps {
//                 sh 'cd /home/mech_mind_sdk/JenkinsTestMMind' // 切换到自定义工作目录
//                 sh 'python3 MyJenkinsTest\\name.py' // 在自定义工作目录中执行构建步骤
//             }
//         }
//     }
// }


pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                dir(path: '/home/mech_mind_sdk/JenkinsTestMMind') {
                    // 在自定义工作路径下进行代码检出
                    checkout([$class: 'GitSCM', branches: [[name: '*/main']], doGenerateSubmoduleConfigurations: false, extensions: [], submoduleCfg: [], userRemoteConfigs: [[url: 'https://github.com/changlelian/Jenkinstest.git']]])
                }
            }
        }
        stage('Build') {
            steps {
                // 在自定义工作路径下执行构建步骤
                sh 'python MyJenkinsTest/name.py'
            }
        }
    }
}

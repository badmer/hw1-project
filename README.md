# hw1-project
工程化软件项目作业题
=========================

### 要求：
    1.构建一个可执行程序服务，在init.rc里启动
    2.服务通过Binder提供IPC接口
    3.构建一个APK，调用服务的的IPC接口
    4.重点考察工程建立，如果时间来不及代码部分优先级可降低

### 编译流程：
    1. source env/env_android27.sh
    2. build.sh
    3. install.sh

### 目录文件简介:
    envs：设置平台环境变量
    platform-tool：存放不同平台的依赖文件如工具链，库，脚本，配置文件等
    src:存放源码
    dist:存放编译结果
    build.sh:编译脚本
    install.sh:安装脚本，安装你的程序到模拟器


### 交作业流程:
    1. Fork本项目
    2. 建立自己组名的分支，修改完成作业
    3. 发Pull Request到本项目，注意：推送到组名分支而非Master

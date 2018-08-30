#!/bin/sh

name=`echo $1 | cut -d \. -f 1`
ss=`echo $1 | cut -d \. -f 2`

if [ ss='c' ];
    then
        command `gcc $1 -o ${name}`
    elif [ ss='cpp' ]
    then
        command `g++ $1 -o ${name}`
fi

./${name}
rm ${name}


#!/bin/bash 
	path='/d/Disk/code_local2/jsb-link/frameworks/runtime-src/proj.android-studio/app/'
	content=$(cat ${path}version.properties)
	echo "读取内容:$content"
	#读取文件的VERSION_CODE对应的value，保存versionCode变量
	versionCode=`grep VERSION_CODE ${path}version.properties|cut -d'=' -f2`
	#将versionCode+1，得到累加后的addVersionCode
	addVersionCode=`expr $versionCode + 1`
	echo "versionCode====$versionCode"
	# 将addVersionCode重新累加赋值给文件的VERSION_CODE
	sed -i "s#^VERSION_CODE=.*#VERSION_CODE=${addVersionCode}#g"  ${path}version.properties
	content=$(cat ${path}version.properties)
	addVersionCode=`grep VERSION_CODE ${path}version.properties|cut -d'=' -f2`
	echo "替换之后====$content"
	echo "addVersionCode====$addVersionCode"
	#判断versionCode是否累加成功， -gt标识大于返回true
	if [ $addVersionCode -gt $versionCode ]
	then
	# 打包apk
	#gradlew 对应目录
	BUILD_TOOL_PATH='/d/Disk/code_local2/jsb-link/frameworks/runtime-src/proj.android-studio'
	echo "开始打包..."
	#cd $BUILD_TOOL_PATH && ./gradlew assembleinsectRelease
	 cd $BUILD_TOOL_PATH && ./gradlew assembleRelease
	openRootPath='D:\Disk\code_local2\jsb-link\frameworks\runtime-src\proj.android-studio\app'
	#打包完成打开包所在的目录，当然，程序里面的这面绝对路径请替换成你对应的路径，不然程序运行不会成功
	explorer $openRootPath'\build\outputs\apk\insect\release'
	else
	echo "error : versionCode未加1"
        fi
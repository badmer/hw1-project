
cd ~/Desktop/release_apk
mkdir -p log


echo "启动模拟器"
emulator -netdelay none -netspeed full -avd $firstExistDeviceName > log/launchEmulator.log &
echo "启动模拟器中，等待30秒后再次尝试获取运行设备名称"
sleep 30
firstDeviceName=`adb devices|sed -n '2p'|awk '{print $1}'`
echo "再次尝试获取运行中的设备名称是:$firstDeviceName"

echo "安装apk"
lastAPK=`ls -t *.apk | sed -n '1p'`
adb -s $firstDeviceName install -r $lastAPK > log/installAPK.log
code=$?
if [ "$code" = "0" ];
    then
        echo "安装apk成功"
    else
        echo "安装apk失败code:$code"
        exit "$code"
fi

echo "启动apk"
adb -s $firstDeviceName shell am start -n "com.jian.test/com.jian.xxx.activities.LaunchActivity" -a android.intent.action.MAIN -c android.intent.category.LAUNCHER
code=$?
if [ "$code" = "0" ];
    then
        echo "启动apk成功"
    else
        echo "启动apk失败code:$code"
        exit "$code"
fi

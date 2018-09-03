#!/bin/sh

source $SYS_ROOT/envs/env_android27.sh

$CMAKE_DIR/cmake $SYS_ROOT/src/service/
make -C $SYS_ROOT/src/service
cp $SYS_ROOT/src/service/c_service $SYS_ROOT/dist
cp $SYS_ROOT/src/service/c_service $SYS_ROOT/platform-tool/aosp6.0/bin

cd $SYS_ROOT/src/apk/MyApplication1
./gradle assembleRelease
cp ./calculator.apk $SYS_ROOT/dist
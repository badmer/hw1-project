#!bin/sh
#the img is too big to unupload

cd ${SYS_ROOT}/platform-tool/$AOSP_V/img_dir/
unpackbootimg -i ./system.img -o ./sys_dir
cp ${SYS_ROOT}/dist/c_service ./sys_dir/system/bin
cp ${SYS_ROOT}/$SYS_ROOT/platform-tool/$AOSP_V/init.rc ./sys_dir/out/target/product/

mkbootimg ./sys_dir system.img
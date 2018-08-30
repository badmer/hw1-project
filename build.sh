#1.compile the source code
cd ${SYS_ROOT}/src/service
${SYS_ROOT}/platform-tool/cmake-3.12.1/cmake
make
#2.uncompress the img file and modify
cd ${SYS_ROOT}/platform-tool/material/
unpackbootimg -i ./system.img -o ./sys_dir
cp ${SYS_ROOT}/dist/service/system/bin ./sys_dir
#3.modify the init.rc file and compress the img
${SYS_ROOT}/src/patch.sh ./sys_dir/out/target/product/generic/root/init.rc
mkbootimg ./sys_dir system.img
#4.start the system
emulator
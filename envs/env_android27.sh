export SYS_ROOT=/hw1-project/
export AOSP_V='aosp6.0'
export CC=$SYS_ROOT/platform-tool/$AOSP_V/tools/arm-linux-androideabi-gcc
export CPP=$SYS_ROOT/platform-tool/$AOSP_V/tools/arm-linux-androideabi-g++
export CMAKE_DIR=$SYS_ROOT/platform-tool/$AOSP_V/tools/cmake-3.12.1

export PATH=$PATH:$SYS_ROOT/platform-tool/$AOSP_V/bin：$SYS_ROOT/platform-tool/$AOSP_V/tools
export LD_LIBRARY_PATH=$SYS_ROOT/platform-tool/$AOSP_V/lib:$LD_LIBRARY_PATH
export LIBRARY_PATH=$SYS_ROOT/platform-tool/$AOSP_V/lib:$LIBRARY_PATH
export C_INCLUDE_PATH=$SYS_ROOT/platform-tool/$AOSP_V/include:$C_INCLUDE_PATH
export CPLUS_INCLUDE_PATH=$SYS_ROOT/platform-tool/$AOSP_V/include:$CPLUS_INCLUDE_PATH
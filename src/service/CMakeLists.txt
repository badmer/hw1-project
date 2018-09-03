PROJECT(c_service)

SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_C_COMPILER   arm-linux-androideabi-gcc)
SET(CMAKE_CXX_COMPILER   arm-linux-androideabi-g++)

INCLUDE_DIRECTORIES($SYS_ROOT/platform-tool/$AOSP_V/include)
INCLUDE_DIRECTORIES($SYS_ROOT/src/service/)
LINK_DIRECTORIES($SYS_ROOT/platform-tool/$AOSP_V/lib)

AUX_SOURCE_DIRECTORY($SYS_ROOT/src/service/ DIR_SRCS)

SET(CURRENT_DIR ${DIR_SRCS})

SET(LIBRARIES libbinder.so)

ADD_EXECUTABLE(./c_service ${CURRENT_DIR})
ADD_LIBRARY(libclient.so $SYS_ROOT/src/service/client.c)

TARGET_LINK_LIBRARIES(./service ${LIBRARY_PATH})
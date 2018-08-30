CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(HELLO) 
AUX_SOURCE_DIRECTORY(. SRC_LIST)
#SET(SRC_LIST ../../src/service/main.c)
ADD_EXECUTABLE(hello ${SRC_LIST})
#库所在位置
#target_link_libraries(hello ../lib/libart.so)

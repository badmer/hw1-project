LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := Myjni 
LOCAL_SRC_FILES := hello.cpp
LOCAL_LDLIBS +=-L$(SYSROOT)/usr/lib -lm -llog
include $(BUILD_SHARED_LIBRARY)
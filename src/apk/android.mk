LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := MyJni 
LOCAL_SRC_FILES := test.c
LOCAL_LDLIBS +=-L$(SYSROOT)/usr/lib -lm -llog
include $(BUILD_SHARED_LIBRARY)
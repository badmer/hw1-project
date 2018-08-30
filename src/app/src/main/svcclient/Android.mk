LOCAL_PATH:=$(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES:=JACK_Client.cpp
LOCAL_SHARED_LIBRARIES:=libutils libbinder
LOCAL_LDLIBS    := -lm -llog #解决undefined reference to `__android_log_print'
LOCAL_MODULE_TAGS:=optional
LOCAL_MODULE:=libJACK_Client
LOCAL_PRELINK_MODULE:=false
include $(BUILD_SHARED_LIBRARY)


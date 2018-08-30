LOCAL_PATH:=$(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES:=test.cpp
LOCAL_SHARED_LIBRARIES:=libJACK_Client libutils
LOCAL_LDLIBS    := -lm -llog #解决undefined reference to `__android_log_print'
LOCAL_MODULE_TAGS:=optional
LOCAL_MODULE:=JACK_svctest
include $(BUILD_EXECUTABLE)

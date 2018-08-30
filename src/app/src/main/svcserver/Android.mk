LOCAL_PATH:=$(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES:=JACK_server.cpp
LOCAL_SHARED_LIBRARIES:=libutils libbinder libJACK_Service
LOCAL_MODULE_TAGS:=optional
LOCAL_MODULE:=JACK_server
include $(BUILD_EXECUTABLE)

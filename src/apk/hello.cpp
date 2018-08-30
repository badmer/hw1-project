//
// Created by 804596442 on 2018/8/30.
//
#include <com_example_a804596442_myapplication_Myjni.h>
#include <android/log.h>

#define LOG_TAG "infoo"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

JNIEXPORT jstring JNICALL Java_com_chenxin_testndk_MyJni_get
  (JNIEnv *env, jclass jz){

        LOGI("hello，这里是native层");
        return env->NewStringUTF("hello jni , you are so easy!");

  }


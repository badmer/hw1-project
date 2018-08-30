#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring

JNICALL
Java_com_msi_jnicmake_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_msi_jnicmake_MainActivity_getStr(JNIEnv *env, jobject instance) {

    // TODO


    return env->NewStringUTF("I'm from C string!!!!");
}
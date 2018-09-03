#include <jni.h>
#include <string>
#include "Counter.h"
using std::string;
extern "C"
JNIEXPORT jdouble JNICALL
Java_com_bruce_counter_MainActivity_stringFromC(JNIEnv *env, jobject instance, jstring s_) {
    const char *s = env->GetStringUTFChars(s_, 0);

    // TODO
//    env->ReleaseStringUTFChars(s_, s);
    string str=s;
    delete s;
    Counter *c=new Counter();
    double d=c->coutn(str);
    delete c;
    return d;
}
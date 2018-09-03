#include <jni.h>
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_xiebing_myapplication1_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C"
JNIEXPORT void JNICALL
Java_com_example_xiebing_myapplication1_MainActivity_changeValue(
        JNIEnv *env,
        jobject obj /* this */) {

    jclass clazz = env->GetObjectClass(obj);

    //be careful Ljava/lang/String
    jfieldID string_fieldID = env->GetFieldID(clazz, "content", "Ljava/lang/String;");
    jstring content = (jstring)env->GetObjectField(obj, string_fieldID);
    const char* str = env->GetStringUTFChars(content, 0);
    //get value

    std::cout << str;/* 显示传入的字符串参数 prompt */

    std::string tmp(str);

    int pos=0;
    int mod=0;

    if( (pos=tmp.find('+'))>=0 )
    {
        mod=1;
    }
    else if((pos=tmp.find('-'))>=0)
    {
        mod=2;
    }
    else if((pos=tmp.find('*'))>=0)
    {
        mod=3;
    }
    else if((pos=tmp.find('/'))>=0)
    {
        mod=4;
    } else{
        //error
    }

    std::string left,right;
    left=tmp.substr(0,pos);
    right=tmp.substr(pos+1,tmp.size()-pos-1);

    double a;
    std::stringstream ssa;
    ssa << left;
    ssa >> a;

    double b;
    std::stringstream ssb;
    ssb << right;
    ssb >> b;

    double res;
    switch(mod)
    {
        case 1:
            res= a+b;
            break;
        case 2:
            res= a-b;
            break;
        case 3:
            res =a*b;
            break;
        case 4:
            res= a/b;
            break;
        default:
            break;
    }
    std::string output=std::to_string(res);
    //change content value
    jstring jhello = env->NewStringUTF(output.c_str());
    env->SetObjectField(obj, string_fieldID, jhello);

    env->ReleaseStringUTFChars(content, str);

    return;

}

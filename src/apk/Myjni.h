#include <jni.h>
/* Header for class com_tcl_tbrowser3_NativeClass */

#ifndef _Included_com_tcl_tbrowser3_NativeClass
#define _Included_com_tcl_tbrowser3_NativeClass
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_tcl_tbrowser3_NativeClass
 * Method:    tbrowserLoadUrlWithName
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_tcl_tbrowser3_NativeClass_tbrowserLoadUrlWithName
  (JNIEnv *, jclass, jstring, jstring);
#ifdef __cplusplus
}
#endif
#endif
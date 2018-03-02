#include <jni.h>
#include <string>

#include "include/forthird-lib.h"

extern "C"
JNIEXPORT int JNICALL
Java_com_lyman_usethirdso_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */,jint a,jint b) {
    const char *hello = "Hello from C++ Me";
    int result = add(a,b);
    //return env->NewStringUTF((const char *) add(a, b));
    return result;
}

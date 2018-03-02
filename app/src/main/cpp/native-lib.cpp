#include <jni.h>
#include <string>
//／







extern "C"
JNIEXPORT jstring JNICALL
Java_com_lyman_myndkdemo_SecondActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++ Me";
    return env->NewStringUTF(hello.c_str());
}

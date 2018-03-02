//
// Created by 叶立民 on 2017/6/9.
//
#include "com_lyman_oldusendkdemo_MainActivity.h"

JNIEXPORT jstring JNICALL Java_com_lyman_oldusendkdemo_MainActivity_getName
        (JNIEnv *env, jobject js){
    return env->NewStringUTF("Lyman1");
}


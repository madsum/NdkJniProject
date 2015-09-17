#include "TestJNIConstructor.h"
#include "MyJniLog.h"
#include <stdlib.h>

JNIEXPORT jobject JNICALL Java_com_ma_jni_TestJNIConstructor_getIntegerObject
        (JNIEnv *env, jobject thisObj, jint number) {
    // Get a class reference for java.lang.Integer
    jclass cls = (env)->FindClass("java/lang/Integer");

    // Get the Method ID of the constructor which takes an int
    jmethodID midInit = (env)->GetMethodID(cls, "<init>", "(I)V");
    if (NULL == midInit) return NULL;
    // Call back constructor to allocate a new instance, with an int argument
    jobject newObj = (env)->NewObject(cls, midInit, number);

    // Try runnning the toString() on this newly create object
    jmethodID midToString = (env)->GetMethodID(cls, "toString", "()Ljava/lang/String;");
    if (NULL == midToString) return NULL;
    jstring resultStr = (jstring) (env)->CallObjectMethod(newObj, midToString);
    const char *resultCStr = (env)->GetStringUTFChars(resultStr, NULL);
    LOGI("In C: the number is %s\n", resultCStr);

    return newObj;
}

JNIEXPORT jobject JNICALL Java_com_ma_jni_TestJNIConstructor_getAClassInstance
        (JNIEnv *env, jobject obj, jint a_int, jstring a_str) {
    LOGI("Enter my class method.");
    jclass a_clas = (env)->FindClass("com/ma/jni/AClass");

    if (NULL == a_clas) {
        LOGE("a_clas is NULL");
        return NULL;
    }
    jmethodID a_ctor = env->GetMethodID(a_clas, "<init>", "(I, Ljava/lang/String;)V");
    if (NULL == a_ctor) {
        LOGE("a_clas is NULL");
        return NULL;
    }

    jobject newObj = env->NewObject(a_clas, a_ctor, a_int, a_str);

    if (NULL == newObj)
    {
        LOGE("newObj is NULL");
        return NULL;
    }

    return newObj;
}


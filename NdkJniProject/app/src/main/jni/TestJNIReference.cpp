#include "TestJNIReference.h"
#include "MyJniLog.h"
#include <stdlib.h>

// Global Reference to the Java class "java.lang.Integer"
static jclass classInteger;
static jmethodID midIntegerInit;

jobject getInteger(JNIEnv *env, jobject thisObj, jint number) {

// Get a class reference for java.lang.Integer if missing
    if (NULL == classInteger) {
        LOGI("Find java.lang.Integer\n");
        classInteger = (env)->FindClass("java/lang/Integer");
    }
    if (NULL == classInteger) return NULL;

// Get the Method ID of the Integer's constructor if missing
    if (NULL == midIntegerInit) {
        LOGI("Get Method ID for java.lang.Integer's constructor\n");
        midIntegerInit = (env)->GetMethodID(classInteger, "<init>", "(I)V");
    }
    if (NULL == midIntegerInit) return NULL;

// Call back constructor to allocate a new instance, with an int argument
    jobject newObj = (env)->NewObject(classInteger, midIntegerInit, number);
    LOGI("In C, constructed java.lang.Integer with number %d\n", number);
    return newObj;
}

JNIEXPORT jobject JNICALL Java_com_ma_jni_TestJNIReference_getIntegerObject
        (JNIEnv *env, jobject thisObj, jint number) {
    return getInteger(env, thisObj, number);
}

JNIEXPORT jobject JNICALL Java_com_ma_jni_TestJNIReference_anotherGetIntegerObject
        (JNIEnv *env, jobject thisObj, jint number) {
    return getInteger(env, thisObj, number);
}
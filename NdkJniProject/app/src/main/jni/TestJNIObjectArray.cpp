#include "TestJNIObjectArray.h"
#include "MyJniLog.h"
#include <stdlib.h>

JNIEXPORT jobjectArray JNICALL Java_com_ma_jni_TestJNIObjectArray_sumAndAverage
        (JNIEnv *env, jobject thisObj, jobjectArray inJNIArray) {
    // Get a class reference for java.lang.Integer
    jclass classInteger = (env)->FindClass("java/lang/Integer");
    // Use Integer.intValue() to retrieve the int
    jmethodID midIntValue = (env)->GetMethodID(classInteger, "intValue", "()I");
    if (NULL == midIntValue) return NULL;

    // Get the value of each Integer object in the array
    jsize length = (env)->GetArrayLength(inJNIArray);
    jint sum = 0;
    int i;
    for (i = 0; i < length; i++) {
        jobject objInteger = (env)->GetObjectArrayElement(inJNIArray, i);
        if (NULL == objInteger) return NULL;
        jint value = (env)->CallIntMethod(objInteger, midIntValue);
        sum += value;
    }
    double average = (double) sum / length;
    LOGI("In C, the sum is %d\n", sum);
    LOGI("In C, the average is %f\n", average);

    // Get a class reference for java.lang.Double
    jclass classDouble = (env)->FindClass("java/lang/Double");

    // Allocate a jobjectArray of 2 java.lang.Double
    jobjectArray outJNIArray = (env)->NewObjectArray(2, classDouble, NULL);

    // Construct 2 Double objects by calling the constructor
    jmethodID midDoubleInit = (env)->GetMethodID(classDouble, "<init>", "(D)V");
    if (NULL == midDoubleInit) return NULL;
    jobject objSum = (env)->NewObject(classDouble, midDoubleInit, (double) sum);
    jobject objAve = (env)->NewObject(classDouble, midDoubleInit, average);
    // Set to the jobjectArray
    (env)->SetObjectArrayElement(outJNIArray, 0, objSum);
    (env)->SetObjectArrayElement(outJNIArray, 1, objAve);

    return outJNIArray;
}
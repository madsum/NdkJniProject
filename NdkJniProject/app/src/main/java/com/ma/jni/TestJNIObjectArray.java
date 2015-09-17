package com.ma.jni;

import android.util.Log;

public class TestJNIObjectArray {


    // Native method that receives an Integer[] and
    //  returns a Double[2] with [0] as sum and [1] as average
    private native Double[] sumAndAverage(Integer[] numbers);

    public static void test() {
        Integer[] numbers = {11, 22, 32};  // auto-box
        Double[] results = new TestJNIObjectArray().sumAndAverage(numbers);
        Log.i("tag", "In Java, the sum is " + results[0]);  // auto-unbox
        Log.i("tag", "In Java, the average is " + results[1]);
    }
}
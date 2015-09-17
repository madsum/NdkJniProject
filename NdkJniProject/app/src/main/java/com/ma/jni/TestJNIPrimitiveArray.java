package com.ma.jni;

import android.util.Log;

public class TestJNIPrimitiveArray {

    // Declare a native method sumAndAverage() that receives an int[] and
    //  return a double[2] array with [0] as sum and [1] as average
    private native double[] sumAndAverage(int[] numbers);

    // Test Driver
    public static void test() {
        int[] numbers = {22, 33, 33};
        double[] results = new TestJNIPrimitiveArray().sumAndAverage(numbers);
        Log.i("tag","In Java, the sum is " + results[0]);
        Log.i("tag", "In Java, the average is " + results[1]);
    }
}
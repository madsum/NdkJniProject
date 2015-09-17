package com.ma.jni;

import android.util.Log;

public class TestJNIPrimitive {


    // Declare a native method average() that receives two ints and return a double containing the average
    private native double average(int n1, int n2);

    // Test Driver
    public static void testMe() {
        Log.i("tag","In Java, the average is " + new TestJNIPrimitive().average(3, 2));
    }
}
package com.ma.jni;

import android.util.Log;

/**
 * Created by masum on 16/09/15.
 */
public class TestJNIInstanceVariable {

    private int number = 88;
    private String message = "Hello from Java";

    // Declare a native method that modifies the instance variables
    private native void modifyInstanceVariable();

    // Test Driver
    public static void testMe() {
        TestJNIInstanceVariable test = new TestJNIInstanceVariable();
        test.modifyInstanceVariable();
        Log.i("tag", "In Java, int is " + test.number);
        Log.i("tag", "In Java, String is " + test.message);
    }
}

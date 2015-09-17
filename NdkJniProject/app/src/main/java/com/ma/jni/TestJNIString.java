package com.ma.jni;

import android.util.Log;

public class TestJNIString {

    // Native method that receives a Java String and return a Java String
    private native String sayHello(String msg);

    public static void test() {
        String result = new TestJNIString().sayHello("Hello from Java");
        Log.i("tag", "In Java, the returned string is: " + result);
    }
}
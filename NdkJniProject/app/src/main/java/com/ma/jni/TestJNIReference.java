package com.ma.jni;

import android.util.Log;

public class TestJNIReference {

    // A native method that returns a java.lang.Integer with the given int.
    private native Integer getIntegerObject(int number);

    // Another native method that also returns a java.lang.Integer with the given int.
    private native Integer anotherGetIntegerObject(int number);

    public static void test() {
        TestJNIReference test = new TestJNIReference();
        Log.i("tag", " "+test.getIntegerObject(1));
        Log.i("tag", " " + test.getIntegerObject(2));
        Log.i("tag", " "+ test.anotherGetIntegerObject(11));
        Log.i("tag", " " + test.anotherGetIntegerObject(12));
        Log.i("tag", " " + test.getIntegerObject(3));
        Log.i("tag", " " + test.anotherGetIntegerObject(13));
    }
}
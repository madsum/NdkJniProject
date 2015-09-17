package com.ma.jni;

import android.util.Log;

public class TestJNIConstructor {

    // Native method that calls back the constructor and return the constructed object.
    // Return an Integer object with the given int.
    private native Integer getIntegerObject(int number);

    private native AClass getAClassInstance(int a, String str);

    public static void test() {
        TestJNIConstructor obj = new TestJNIConstructor();
        Log.i("tag", "In Java, the number is :" + obj.getIntegerObject(9999));
        AClass a = obj.getAClassInstance(100, "niec");
        if(a == null){
            return;
        }
        Log.i("tag", "In Java, a.a_int :" + a.a_int+" and a.s_string: "+a.s_string);
    }
}
package com.example.plasma;

import android.app.Activity;
import android.os.Bundle;

import com.ma.jni.TestJNIInstanceVariable;

public class MainActivity extends Activity {

    static {
        System.loadLibrary("openshadow");
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        testMethods();
    }

    public void testMethods(){
        TestJNIInstanceVariable.testMe();
       // TestJNIPrimitive.testMe();
       // TestJNIString.test();
       // TestJNIPrimitiveArray.test();
       // TestJNIStaticVariable.test();
       // TestJNICallBackMethod.test();
       // TestJNIConstructor.test();
       // TestJNIObjectArray.test();
       // TestJNIReference.test();
    }
}

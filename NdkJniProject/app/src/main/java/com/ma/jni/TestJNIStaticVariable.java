package com.ma.jni;

public class TestJNIStaticVariable {


    // Static variables
    private static double number = 55.66;

    // Declare a native method that modifies the static variable
    private native void modifyStaticVariable();

    // Test Driver
    public static void test() {
        TestJNIStaticVariable test = new TestJNIStaticVariable();
        test.modifyStaticVariable();
        System.out.println("In Java, the double is " + number);
    }
}
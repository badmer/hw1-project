package com.example.a804596442.myapplication;

public class Myjni {
    static{
        System.loadLibrary("xx.so");
    }
    public native static String get();
}

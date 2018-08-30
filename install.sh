#!/bin/bash

files=$(ls | grep .apk)

for file in $files
do
    echo $file
    adb install £­r $file
done
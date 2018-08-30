#!/bin/bash
echo "on property:A3=SampleService">>/system/core/rootdir/init.rc
echo "service SampleService /system/bin/SampleService.cpp">>/system/core/rootdir/init.rc
echo "class main">>/system/core/rootdir/init.rc

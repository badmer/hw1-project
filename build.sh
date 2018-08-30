#!/bin/bash
cd dist/cmake
cmake ../../platform-tool/cmake
make
./hello

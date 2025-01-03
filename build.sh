#!/bin/sh
[ -z $CONFIG ] && config=Release || config="$CONFIG"

cmake . \
    -B build \
    -DCMAKE_C_FLAGS=-m32 \
    -DCMAKE_CXX_FLAGS=-m32 \
    -DCMAKE_BUILD_TYPE=$config
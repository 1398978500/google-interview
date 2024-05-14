#!/bin/bash
# 没有build则创建
[ -d "build" ] || mkdir build
cd build && cmake ../practice && make

if [[ $1 == "test" ]]
then
    make test
fi


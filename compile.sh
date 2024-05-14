#!/bin/bash

# 没有build则创建
if [[ $# < 1 || $1 == "" ]]
then
    # 编译
    [ -d "build" ] || mkdir build
    cd build && cmake ../practice && make -j4
elif [[ $1 == "test" ]]
then
    # 执行gtest
    [ -d "build" ] && cd build && make test
elif [[ $1 == "clean" ]]
then
    # 清理make缓存
    [ -d "build" ] && cd build && make clean
elif [[ $1 == "cleanall" ]]
then
    # 清理cmake和make缓存
    [ -d "build" ] && rm build -r
else
    echo "./compile [argv]"
    echo "argv可选:"
    echo "  没有参数:编译"
    echo "  test: 执行所有gtest相关可执行文件(需要先编译)"
    echo "  clean: 清理make缓存"
    echo "  cleanall:清理cmake和make缓存"
fi


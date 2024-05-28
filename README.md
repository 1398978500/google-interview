本项目主要是clone "Google Interview University"并进行学习

[进度查看](google-interview.md)

## 如何使用
```shell
# 编译链接
./compile.sh
# 或者在项目目录下执行
mkdir build && cd build && cmake ../practice

# 编译并执行 gtest需要测试的内容
./compile.sh test

# 清理make缓存 即make clean
./compile.sh clean

# 清理cmake以及make缓存
./compile.sh cleanall

```

## 准备
* cmake
```
# 下载cmake
sudo apt install cmake
```

* gtest
```
# 下载gtest
sudo apt install libgtest-dev
```

## 常见问题
1. 问题: 使用./compile.sh test 没有日志      
   解决: 日志在目录build/Testing/Temporary下查找


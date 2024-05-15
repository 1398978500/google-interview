cmake_minimum_required(VERSION 3.5) # 设置CMake最小版本

project(practice) # 设置工程名

enable_testing() # 开启测试，否则无法执行make test

add_subdirectory(myVector)
add_subdirectory(hashTable)
add_subdirectory(hashTableLinked)
add_subdirectory(sorting)
add_subdirectory(test)


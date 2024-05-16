# 偷个懒,写个函数
# 生成一个可执行文件函数
# name :test文件名(去掉后缀(.cpp))
# include_name :需要包含的头文件路径
# lib_name :需要链接的库路径
# is_gtest :是否需要链接gtest库
function(gen_exe test_name include_name lib_name is_gtest)
    # 可执行文件
    add_executable(${test_name} ${test_name}.cpp)

    # 有目录则包含
    if(NOT ${include_name} EQUAL "")
        target_include_directories(${test_name}
            PRIVATE ${PROJECT_SOURCE_DIR}/${include_name}

            if(${include_name} EQUAL "queueList")
                PRIVATE ${PROJECT_SOURCE_DIR}/linkedList
            endif()
        )
    endif()

    # 有库则连接
    if(NOT ${lib_name} EQUAL "")
        target_link_libraries(${test_name}
            ${lib_name}
        )
    endif()

    if(${is_gtest} EQUAL 1)
        target_link_libraries(${test_name}
            gtest
            pthread
        )
        # 生成测试 make test命令
        add_test(${test_name} ${CMAKE_BINARY_DIR}/test/${test_name}) # 添加测试，保证make test可以执行该测试用例
    endif()
endfunction()

# 动态数组
gen_exe("MyVectorTest" "myVector" "MyVector" 0)
# 链表
gen_exe("LinkedListTest" "linkedList" "" 0)
# 链表实现队列
gen_exe("QueueListTest" "queueList" "" 0)
# 数组实现队列
gen_exe("QueueArrayTest" "queueArray" "" 0)
# hash table 开放寻址法
gen_exe("HashTableTest" "hashTable" "HashTable" 0)
# hash table 拉链法
gen_exe("HashTableLinkedTest" "hashTableLinked" "HashTableLinked" 0)
# 二分法
gen_exe("binarySearchTest" "" "" 1)
# 位操作
gen_exe("absTest" "" "" 1)
# BST
gen_exe("BSTSimpleTest" "BSTSimple" "" 0)
# heap
gen_exe("HeapSimpleTest" "heap" "" 1)

# sort
gen_exe("SortTest" "sorting" "Sort" 1)
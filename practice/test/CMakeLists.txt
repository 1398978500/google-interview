# 生成一个可执行文件函数
# name :test文件名(去掉后缀(.cpp))
# include_name :需要包含的头文件路径
# lib_name :需要链接的库路径
function(gen_exe test_name include_name lib_name)
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
endfunction()

gen_exe("MyVectorTest" "myVector" "MyVector")
gen_exe("LinkedListTest" "linkedList" "")
gen_exe("QueueListTest" "queueList" "")
gen_exe("QueueArrayTest" "queueArray" "")
gen_exe("HashTableTest" "hashTable" "HashTable")
gen_exe("HashTableLinkedTest" "hashTableLinked" "HashTableLinked")

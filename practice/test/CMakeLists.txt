# 生成一个可执行文件函数
# name :test文件名(去掉后缀(.cpp))
# include_name :需要包含的头文件路径
# lib_name :需要链接的库路径
function(gen_exe test_name include_name lib_name)
    add_executable(${test_name} ${test_name}.cpp)
    
    target_include_directories(${test_name}
        PRIVATE ${PROJECT_SOURCE_DIR}/${include_name}
    )

    target_link_libraries(${test_name}
        ${lib_name}
    )
endfunction()

gen_exe("MyVectorTest" "myVector" "MyVector")
gen_exe("LinkedListTest" "linkedList" "LinkedList")


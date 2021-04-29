# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (main)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(main ${DIR_SRCS}) # 这样写是将查找到的所有源文件都生成

include_directories(./A)

include_directories(./B)

# 添加 A 子目录
add_subdirectory(A)
# 添加 B 子目录
add_subdirectory(B)

# 添加链接库
target_link_libraries(main A B)
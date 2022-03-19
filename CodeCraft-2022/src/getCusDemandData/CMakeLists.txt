cmake_minimum_required (VERSION 2.8)

aux_source_directory(. DIR_LIB_SRCS)

# 将源代码添加到此项目的可执行文件。
add_library(getCusDemandData ${DIR_LIB_SRCS})

# TODO: 如有需要，请添加测试并安装目标。

# cmake_minimum_required(VERSION <specify CMake version here>)
project(lab6)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(lab6
        BinaryTree.h
        main.cpp
        TreeNode.h)

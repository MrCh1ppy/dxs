cmake_minimum_required(VERSION 3.19)
project(dxs)

set(CMAKE_CXX_STANDARD 20)

add_executable(dxs main.cpp TLinkList.cpp TLinkList.h 链表Union.cpp 链表Merge.cpp 线性表Union.cpp 线性表Merge.cpp)
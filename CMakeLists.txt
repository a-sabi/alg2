cmake_minimum_required(VERSION 3.23)
project(alg)

set(CMAKE_CXX_STANDARD 14)

add_executable(alg main.cpp postfix.cpp postfix.h stack.cpp stack.h LinkedList.cpp LinkedList.h node.cpp node.h infix.cpp infix.h queue.cpp queue.h)

cmake_minimum_required(VERSION 3.28)
project(data_structure)

set(CMAKE_CXX_STANDARD 17)

include_directories(linear-structure)

add_executable(data_structure main.cpp
        linear-structure/List.h
        linear-structure/LinearList.h
        linear-structure/ArrayList.tpp
        linear-structure/Node.h
        linear-structure/Linked.h
        linear-structure/LinkedList.tpp)

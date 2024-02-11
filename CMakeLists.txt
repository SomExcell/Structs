cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(Structs)

include_directories("header/")

set(SOURCES source/main.cpp)

set(HEADERS header/String.h 
		header/String.cpp
		header/list.hpp 
		header/matrix.hpp
		header/binaryTree.hpp)

add_executable(Structs ${SOURCES} ${HEADERS})

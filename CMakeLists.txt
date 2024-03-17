cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(Structs)

include_directories("header/")

set(SOURCES source/main.cpp)

set(HEADERS header/String.h 
		header/String.cpp
		header/List.hpp 
		header/Matrix.hpp
		header/BinaryHeap.hpp
		header/BinarySearchTree.hpp)

add_executable(Structs ${SOURCES} ${HEADERS})

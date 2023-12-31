cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(String)

include_directories("header/")

set(SOURCES source/main.cpp)

set(HEADERS header/String.h header/list.hpp header/String.cpp)

add_executable(String ${SOURCES} ${HEADERS})
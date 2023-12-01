cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

project(List)

include_directories("header/")

set(SOURCES source/main.cpp)

set(HEADERS header/list.h)

add_executable(LIST ${SOURCES} ${HEADERS})
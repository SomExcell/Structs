cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

project(String)

include_directories("header/")

set(SOURCES source/main.cpp source/String.cpp)

set(HEADERS header/String.h)

add_executable(LIST ${SOURCES} ${HEADERS})
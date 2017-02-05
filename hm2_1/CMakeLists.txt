cmake_minimum_required(VERSION 3.6)
project(hm2_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp stock.cpp stock.h history.cpp history.h Constants.h Comparer.cpp Comparer.h Utils.cpp Utils.h analyst.cpp analyst.h)
add_executable(hm2_1 ${SOURCE_FILES})
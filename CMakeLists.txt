cmake_minimum_required(VERSION 3.8)
project(dfp)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp linear-algebra.cpp linear-algebra.h function.cpp function.h dfp.cpp dfp.h wolfe.cpp wolfe.h)
add_executable(dfp ${SOURCE_FILES})
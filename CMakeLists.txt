cmake_minimum_required(VERSION 3.10)
project(zy_algorithm)

set(CMAKE_CXX_STANDARD 11)

include_directories(proj)

add_executable(zy_algorithm
        proj/cmake-build-debug/cmake_install.cmake
        proj/cmake-build-debug/CMakeCache.txt
        proj/cmake-build-debug/main
        proj/cmake-build-debug/Makefile
        proj/cmake-build-debug/my.out
        proj/cmake-build-debug/proj
        proj/cmake-build-debug/Project.cbp
        proj/CMakeLists.txt
        proj/greatMinus.h
        proj/greatMultiple.h
        proj/Makefile
        proj/proj.cpp
        proj/README.md
        proj/sqList.h
        proj/util.h)

cmake_minimum_required(VERSION 3.10)
project(object_pool_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(object_pool_cpp
        main.cpp VeryHardAndSlowCreation.cpp VeryHardAndSlowCreation.h VHSCPool.cpp VHSCPool.h)

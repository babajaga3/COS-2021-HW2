cmake_minimum_required(VERSION 4.1)
project(code)

set(CMAKE_CXX_STANDARD 20)

add_executable(code
        main.cpp
        obj_store_kd.cpp
        obj_store_v.cpp
        object.cpp
        point.cpp
)

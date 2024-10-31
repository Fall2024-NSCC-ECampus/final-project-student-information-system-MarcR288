cmake_minimum_required(VERSION 3.29)
project(Student_Information_System)

set(CMAKE_CXX_STANDARD 20)

add_executable(Student_Information_System main.cpp
        Student.h
        Student.cpp)

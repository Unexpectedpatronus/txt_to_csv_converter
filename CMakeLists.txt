cmake_minimum_required(VERSION 3.26)
project(exam_work C)

set(CMAKE_C_STANDARD 17)

add_executable(exam_work main.c
        dynamic_array.c
        file_operations.c)

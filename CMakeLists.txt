cmake_minimum_required(VERSION 3.25.0)
project(Learning VERSION 0.1.0 LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_compile_options(-std=c11 -Wall -Wextra -Wpedantic -Wshadow)

add_executable(Learning main.c)

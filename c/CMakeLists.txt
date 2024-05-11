cmake_minimum_required(VERSION 3.10)
project(Calculator)

set(CMAKE_C_STANDARD 99)

add_executable(Calculator calc.c math_operations.c)
target_link_libraries(Calculator m)
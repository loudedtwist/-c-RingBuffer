cmake_minimum_required(VERSION 3.12)
project(run_project)

set(CMAKE_CXX_STANDARD 17)
include_directories(ring-buffer)
add_subdirectory(ring-buffer)
add_subdirectory(ring-buffer-test)
add_executable(run_project main.cpp)
target_link_libraries(run_project ring_buffer)

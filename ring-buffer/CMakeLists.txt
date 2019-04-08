cmake_minimum_required(VERSION 3.12)
project(ring_buffer)

set(CMAKE_CXX_STANDARD 17)

add_library(ring_buffer IRingBuffer.hpp Iterator.hpp RingBuffer.cpp RingBuffer.hpp)
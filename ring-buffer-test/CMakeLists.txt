project(ring-buffer-test)
include_directories(Catch2/single_include)
include_directories(../ring-buffer/)
add_executable(ring-buffer-test tests/RingBuffer.cpp)
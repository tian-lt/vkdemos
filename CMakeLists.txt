cmake_minimum_required(VERSION 3.20)
project(vkdemos)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(TEST_RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources)

add_subdirectory(dm1)

#include(CTest)
#enable_testing()
#add_subdirectory(tests)



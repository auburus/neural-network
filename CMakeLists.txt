cmake_minimum_required(VERSION 3.1)
project(neural_network_project)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Use c++ 11. Needs Cmake version 3.1 for it to work
set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE sources "src/*.cpp" "src/*.h")
file(GLOB_RECURSE sources_test "test/*.cpp")


add_executable(neural_network ${sources})

target_include_directories(neural_network PUBLIC "src")

install(TARGETS neural_network DESTINATION ./bin)

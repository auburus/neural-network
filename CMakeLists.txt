cmake_minimum_required(VERSION 3.1)
project(neural_network_project)


# Define the output dirs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Use c++ 11. Needs Cmake version 3.1 for it to work
set(CMAKE_CXX_STANDARD 11)

# Enable testing
enable_testing()


# Main program

file(GLOB_RECURSE sources "src/main/*.cpp" "src/main/*.h")
file(GLOB_RECURSE sources_test "src/test/*.cpp" "include/catch.hpp")


add_executable(neural_network "src/main.cpp" ${sources})

target_include_directories(neural_network PUBLIC "src/main" "include")

install(TARGETS neural_network DESTINATION ./bin)


# Test files
add_executable(unit_tests ${sources_test} ${sources})

target_include_directories(unit_tests PUBLIC "src/main" "include")

install(TARGETS unit_tests DESTINATION ./bin)

add_test(unit_tests "./bin/nn_tests")

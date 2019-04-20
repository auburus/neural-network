cmake_minimum_required(VERSION 3.0)
project(neural_network_project)

file(GLOB_RECURSE sources src/*.cpp src/*.h)
file(GLOB_RECURSE sources_test test/*.cpp)

add_executable(neural_network ${sources})

install(TARGETS neural_network DESTINATION ./bin)

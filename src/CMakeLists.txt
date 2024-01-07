set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_minimum_required(VERSION 3.23)
project(algorithms)

set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

#add_library(${PROJECT_NAME})

add_subdirectory(search)

add_subdirectory(tests)

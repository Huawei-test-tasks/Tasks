cmake_minimum_required(VERSION 3.14)

project(Huawei LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_compile_options(-std=c++17)

option(ENABLE_PARSER_EXCEPTIONS "Enable parser exceptions" OFF)

if(UNIX)
    add_compile_options(-Wall -Werror -Wextra)
endif()

include_directories(Utils)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(Task1)
add_subdirectory(Task2)
add_subdirectory(Task3)

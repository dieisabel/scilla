cmake_minimum_required(VERSION 3.2)
project(scilla)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
    add_compile_options(-g3 -O0)
    add_compile_options(
        -Wall -Wextra -Werror -Wconversion -Wshadow -Wpedantic
        -Wfloat-conversion -Wfloat-equal -Wswitch
    )
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_definitions(RELEASE)
else()
    message(FATAL_ERROR "-- Unknown build type, abort")
endif()
message("-- Build type is ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(core)

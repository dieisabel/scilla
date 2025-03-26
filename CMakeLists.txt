cmake_minimum_required(VERSION 3.2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(scilla)
set(SCILLA_PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

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
message(STATUS "Build type is ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(core)
add_subdirectory(platforms)

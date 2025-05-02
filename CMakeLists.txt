cmake_minimum_required(VERSION 3.22)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PROJECT_NAME scilla)

include("cmake/gcc-arm-none-eabi.cmake")

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project(${CMAKE_PROJECT_NAME}
    LANGUAGES ASM C CXX
)

add_executable(${CMAKE_PROJECT_NAME})

add_subdirectory(cmake/stm32cubemx)
add_subdirectory(Lib)
add_subdirectory(Logic)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    BSP/STM32G4xx_Nucleo/stm32g4xx_nucleo.c
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    BSP/STM32G4xx_Nucleo
)

target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx
)

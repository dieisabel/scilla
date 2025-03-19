set(SCILLA_PLATFORMS_DIR ${SCILLA_PROJECT_ROOT})
cmake_path(APPEND SCILLA_PLATFORMS_DIR "platforms")

set(SCILLA_SUPPORTED_PLATFORMS
    nucleo-g431kb
)

if (NOT SCILLA_PLATFORM)
    message("-- Platform is not selected, supported platforms are:")
    foreach(PLATFORM IN LISTS SCILLA_SUPPORTED_PLATFORMS)
        message("--   ${PLATFORM}")
    endforeach()
    message("-- Set it using SCILLA_PLATFORM variable")
    message(FATAL_ERROR)
endif()

set(SCILLA_PLATFORM_ROOT ${SCILLA_PLATFORMS_DIR})
cmake_path(APPEND SCILLA_PLATFORM_ROOT ${SCILLA_PLATFORM})

if (NOT EXISTS "${SCILLA_PLATFORM_ROOT}" AND NOT IS_DIRECTORY "${SCILLA_PLATFORM_ROOT}")
    message(STATUS "Platform toolchain file is not found")
    message(STATUS "Tried path is ${SCILLA_PLATFORM_TOOLCHAIN_FILE}")
    message(FATAL_ERROR)
endif()
message(STATUS "Platform directory is found")

include(ExternalProject)

ExternalProject_Add(platform
    SOURCE_DIR "${SCILLA_PLATFORM_ROOT}"
    INSTALL_COMMAND ""
)

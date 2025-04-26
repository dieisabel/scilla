target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(${PROJECT_NAME} PRIVATE
    InitCppWrapper.cpp

    task/HeartbeatTask.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE
    # Warnings
    "-Wall" "-Wextra" "-Wshadow" "-Wundef" "-Wconversion" "-Wno-common"
    "-Wfloat-equal" "-Wmissing-include-dirs"

    # Useful compile options
    "-fstack-usage"
)

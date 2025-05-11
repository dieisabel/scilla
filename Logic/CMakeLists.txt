target_compile_options(${PROJECT_NAME} PRIVATE
    # Warnings
    "-Wall" "-Wextra" "-Wshadow" "-Wundef" "-Wconversion" "-Wno-common"
    "-Wfloat-equal" "-Wmissing-include-dirs"

    # Useful compile options
    "-fstack-usage"
)

add_subdirectory(core)
add_subdirectory(drivers)
add_subdirectory(apps)

find_package(Catch2 3 REQUIRED)

set(TEST_PROJECT_NAME "${PROJECT_NAME}_tests")

add_executable(${TEST_PROJECT_NAME}
    main.cpp
)

target_include_directories(${TEST_PROJECT_NAME}
    SYSTEM PRIVATE
        "${SOURCE_DIR}")

target_link_libraries(${TEST_PROJECT_NAME}
    PRIVATE
        Catch2::Catch2
)

add_subdirectory("search")

enable_testing()

include(CTest)
include(Catch)

catch_discover_tests(${TEST_PROJECT_NAME})

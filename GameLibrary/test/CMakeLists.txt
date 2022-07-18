cmake_minimum_required(VERSION 3.0.0)

set(ProjectName Tests)

set(Sources 
    tests.cpp
)

enable_testing()
find_package(GTest REQUIRED)

add_executable(${ProjectName} ${Sources})

target_link_libraries(${ProjectName} PUBLIC 
    gamelibrary
    GTest::gtest_main
)

include(GoogleTest)

add_test(
    NAME ${ProjectName}
    COMMAND ${ProjectName}
)
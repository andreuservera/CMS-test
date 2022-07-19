add_executable(TestsExec tests.cpp)

target_link_libraries(
    TestsExec PUBLIC
    gtest
)
cmake_minimum_required(VERSION 3.0.0)

set(ProjectName CMS)

project(ProjectName)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libs/googletest)
#add_subdirectory(libs/pugixml)
add_subdirectory(test)

add_subdirectory(GameLibrary)

enable_testing()

add_executable(${ProjectName} main.cpp)

target_link_libraries(${ProjectName} gamelibrary)
#target_link_libraries(${ProjectName} pugixml gamelibrary)
#target_link_libraries(${ProjectName} gamelibrary)
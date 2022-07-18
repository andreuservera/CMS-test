cmake_minimum_required(VERSION 3.0.0)

set(ProjectName CMS)

project(ProjectName VERSION 0.1.0)

add_subdirectory(GameLibrary)

add_executable(${ProjectName} main.cpp)

target_link_libraries(${ProjectName} gamelibrary)
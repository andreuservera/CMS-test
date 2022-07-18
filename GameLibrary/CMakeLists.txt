cmake_minimum_required(VERSION 3.0.0)

project(gamelibrary)

enable_testing()

file(GLOB Sources 
    *.cpp    
)
file(GLOB Headers 
    *.h
)

add_library(gamelibrary STATIC ${Sources} ${Headers})

add_subdirectory(test)
cmake_minimum_required(VERSION 3.0.0)

set(ProjectName CMS)

project(ProjectName)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libs/googletest)
#add_subdirectory(libs/pugixml)
add_subdirectory(test)

add_subdirectory(GameLibrary)
add_subdirectory(utils)

enable_testing()


## Use for Address Sanitizer
add_compile_options(-Wall -Wextra -pedantic -Werror -fsanitize=address -static-libasan)
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address -static-libasan")
## Use for Valgrind
#add_compile_options(-Wall -Wextra -pedantic -Werror)
#set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
#set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG}")

add_executable(${ProjectName} main.cpp)

target_link_libraries(${ProjectName} 
    gamelibrary
    utils
)
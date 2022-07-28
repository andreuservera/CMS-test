file(GLOB Sources 
    *.cpp    
)
file(GLOB Headers 
    *.h
)

add_subdirectory(${CMAKE_SOURCE_DIR}/libs/pugixml ${CMAKE_SOURCE_DIR}/build/pugixml/build)

add_library(gamelibrary STATIC ${Sources} ${Headers})

target_link_libraries(
    gamelibrary PUBLIC
    pugixml
)
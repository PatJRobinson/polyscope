# Create a library for the viewer code
add_library(
    stb 
    stb_impl.cpp
    )

target_include_directories(stb PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})    
target_include_directories(stb PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})   

set_target_properties(stb PROPERTIES POSITION_INDEPENDENT_CODE TRUE)

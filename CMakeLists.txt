cmake_minimum_required(VERSION 3.5...3.22)

# project(polyscope)

### Policy settings
cmake_policy(SET CMP0054 NEW)   # don't implicitly dereference inside if()

## Project options

# Backend
set(POLYSCOPE_BACKEND_OPENGL3_GLFW "ON" CACHE BOOL "Enable openGL3_glfw backend")
set(POLYSCOPE_BACKEND_OPENGL_MOCK "ON" CACHE BOOL "Enable openGL_mock backend")

if("${GLFW_FOUND}")
    message("GLFW: GLFW Has Already Been Added, Skipping")
else("${GLFW_FOUND}")
    message("Adding GLFW")


    FetchContent_Declare(glfw
                        GIT_REPOSITORY https://github.com/PatJRobinson/glfw.git
                        #  GIT_TAG        a098198bcb7058306ec1efc834d8d7f371fa26ed # release-1.0)
    )
    FetchContent_MakeAvailable(glfw)

endif("${GLFW_FOUND}")


### Do anything needed for dependencies and bring their stuff in to scope
add_subdirectory(deps)

### Add things for this project
add_subdirectory(src)

# add_executable(test test.cpp)
# target_link_libraries(test polyscope)

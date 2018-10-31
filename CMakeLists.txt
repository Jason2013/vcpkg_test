cmake_minimum_required(VERSION 3.0)

project(test)

function (allvars)
    get_cmake_property(_variableNames VARIABLES)
    list (SORT _variableNames)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
endfunction()

find_package(glfw3 CONFIG REQUIRED)
find_package(glew REQUIRED)
find_package(glm CONFIG REQUIRED)

# allvars()

add_subdirectory(common)

include_directories(
    ${CMAKE_SOURCE_DIR}
    )

link_libraries(common)

add_subdirectory(tutorial01_first_window)
add_subdirectory(tutorial02_red_triangle)
# add_executable(main tutorial01.cpp)

# target_link_libraries(main PRIVATE
#     glfw
#     GLEW::GLEW
#     opengl32.lib
#     )

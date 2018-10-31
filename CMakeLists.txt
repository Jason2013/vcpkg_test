# CMakeLists.txt
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
message(STATUS glfw3_FOUND)

# allvars()

find_package(glew REQUIRED)
message(STATUS glew_FOUND)

# allvars()

find_package(glm CONFIG REQUIRED)
message(STATUS glm_FOUND)

# allvars()

add_executable(main tutorial01.cpp)

target_include_directories(main PRIVATE
    ${glfw3_DIR}
    ${GLEW_INCLUDE_DIR}
    )

target_link_libraries(main PRIVATE
    glm
    glfw
    GLEW::GLEW
    )

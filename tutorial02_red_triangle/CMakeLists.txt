cmake_minimum_required(VERSION 3.0)

# project(test)

# find_package(glfw3 CONFIG REQUIRED)
# find_package(glew REQUIRED)
# find_package(glm CONFIG REQUIRED)

set(TARGET_NAME tutorial02_red_triangle)
add_executable(${TARGET_NAME} tutorial02.cpp)

target_link_libraries(${TARGET_NAME} PRIVATE
    glfw
    GLEW::GLEW
    opengl32.lib
    )

set_target_properties(${TARGET_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )

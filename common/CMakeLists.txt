cmake_minimum_required(VERSION 3.0)

# project(test)

# find_package(glfw3 CONFIG REQUIRED)
# find_package(glew REQUIRED)
# find_package(glm CONFIG REQUIRED)

set(TARGET_NAME common)
add_library(${TARGET_NAME} STATIC
    shader.cpp
    )

target_include_directories(${TARGET_NAME} PRIVATE
    ${GLEW_INCLUDE_DIRS}
    )

# target_link_libraries(${TARGET_NAME} PRIVATE
#     #    glfw
#     GLEW::GLEW
#     opengl32.lib
#     )

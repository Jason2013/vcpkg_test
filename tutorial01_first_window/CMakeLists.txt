cmake_minimum_required(VERSION 3.0)

# project(test)

# find_package(glfw3 CONFIG REQUIRED)
# find_package(glew REQUIRED)
# find_package(glm CONFIG REQUIRED)

set(TARGET_NAME tutorial01_first_window)
add_executable(${TARGET_NAME} tutorial01.cpp)

target_link_libraries(${TARGET_NAME} PRIVATE
    glfw
    GLEW::GLEW
    opengl32.lib
    )

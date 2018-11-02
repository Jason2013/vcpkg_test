cmake_minimum_required(VERSION 3.0)

project(vcpkg_test)

find_package(glfw3 CONFIG REQUIRED)
find_package(glew REQUIRED)
find_package(glm CONFIG REQUIRED)

add_subdirectory(common)

include_directories(
    ${CMAKE_SOURCE_DIR}
    )

link_libraries(common)

add_subdirectory(tutorial01_first_window)
add_subdirectory(tutorial02_red_triangle)
add_subdirectory(tutorial02_red_triangle2)

cmake_minimum_required(VERSION 3.10)

project(vcpkg_test)

# add_executable(hello main.cpp)

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

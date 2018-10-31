set(TARGET_NAME tutorial01_first_window)
add_executable(${TARGET_NAME} tutorial01.cpp)

target_link_libraries(${TARGET_NAME} PRIVATE
    glfw
    GLEW::GLEW
    opengl32.lib
    )

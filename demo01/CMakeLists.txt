set(TARGET_NAME demo01)
add_executable(${TARGET_NAME}
    main.cpp
    opengl.h
    opengl_cs.cpp
    opengl_util.cpp)

target_link_libraries(${TARGET_NAME} PRIVATE
    glfw
    GLEW::GLEW
    opengl32.lib
    )

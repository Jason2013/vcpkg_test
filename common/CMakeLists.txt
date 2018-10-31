set(TARGET_NAME common)
add_library(${TARGET_NAME} STATIC
    shader.cpp
    )

target_include_directories(${TARGET_NAME} PRIVATE
    ${GLEW_INCLUDE_DIRS}
    )

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

GLFWwindow* window;

int main()
{
    if (!glfwInit())
    {
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_COMPAT_FORWARD, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* glfwWindowHint(GLFW_SAMPLES, 4); */
    window = glfwCreateWindow(1024,768, "Red 2", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeCurrentContext(window);

    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetInputMode(window, GLFW_STICK_KEYS, GL_TRUE);

    do
    {
        glfwSwapBuffers();
        glfwPollEvents();
    }
    while (glfwGetKey(window, GLFW_ESCAPE) != GLFW_PRESSED &&
            !glfwWindowShouldClose());

    glfwDestroyWindow(window);
    return 0;
}


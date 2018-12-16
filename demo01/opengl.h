#ifndef _OPENGL_H
#define _OPENGL_H

#define GL_GLEXT_PROTOTYPES
#define GLX_GLXEXT_PROTOTYPES

#include <GL/glew.h>
#include <GLFW/glfw3.h>

extern GLFWwindow* window;

#include <string>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

int initGL();
void swapBuffers();

// Return handles
GLuint genTexture();
GLuint genRenderProg(GLuint); // Texture as the param
GLuint genComputeProg(GLuint);

void checkErrors(std::string);

#endif

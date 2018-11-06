#include "shader2.h"
#include <GL/glew.h>
/* #include <iostream> */
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

GLuint CompileShader(const char* shaderPath, GLuint shaderType)
{
    GLuint shaderId = glCreateShader(shaderType);

    ifstream stream(shaderPath);
    //vector<char> source;
    string source;
    if (stream.is_open())
    {
        stringstream ss;
        ss << stream.rdbuf();
        stream.close();
        source = ss.str();
    }
    else
    {
        fprintf(stderr, "Cannot open file: %s\n", shaderPath);
        return 0;
    }

    const char* src = source.c_str();
    glShaderSource(shaderId, 1, &src, nullptr);
    glCompileShader(shaderId);

    GLint error;
    GLint log_len;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &error);
    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &log_len);
    if (log_len > 0)
    {
        fprintf(stderr, "Cannot compile file: %s\n", shaderPath);
        return 0;
    }

    return shaderId;
}



GLuint LoadShaders(const char* vertexShaderPath, const char* pixelShaderPath)
{
    GLuint vertexShader = CompileShader(vertexShaderPath, GL_VERTEX_SHADER);
    if (vertexShader == 0)
    {
        return 0;
    }
    GLuint pixelShader = CompileShader(pixelShaderPath, GL_FRAGMENT_SHADER);
    if (pixelShader == 0)
    {
        return 0;
    }
    GLuint programID = glCreateProgram();
    glAttachShader(programID, vertexShader);
    glAttachShader(programID, pixelShader);

    glLinkProgram(programID);

    GLint error;
    GLint log_len;
    glGetProgramiv(programID, GL_LINK_STATUS, &error);
    glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &log_len);
    if (log_len > 0)
    {
        fprintf(stderr, "Cannot link program.\n");
        return 0;
    }
    glDetachShader(programID, vertexShader);
    glDetachShader(programID, pixelShader);
    glDeleteShader(vertexShader);
    glDeleteShader(pixelShader);

    return programID;
}


#include "shader2.h"
#include <ifstream>
#include <vector>
using namespace std;

GLuint CompileShader(const char* shaderPath, GLuint shaderType)
{
    GLuint shaderId = glCreateShader(shaderType);

    ifstream stream(shaderPath);
    vector<char> source;
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

    glShaderSource(shaderId, 1, source.data(), source.size());
    glCompileShader(shaderId);

    GLuint error;
    GLuint log_len;
    glGetParameteri(shaderId, GL_COMPILE_STATUS, &error);
    glGetParameteri(shaderId, GL_LOG_INFO_LENGTH, &log_len);
    if (log_len > 0)
    {
        fprintf(stderr, "Cannot compile file: %s\n", shaderPath);
        return 0;
    }

    return shaderId;
}



GLuint LoaderShaders(const char* vertexShaderPath, const char* pixelShaderPath)
{
    GLuint vertexShader = CompileShader(vertexShaderPath, GL_VERTEX_SHADER);
    if (vertexShader == 0)
    {
        return 0;
    }
    GLuint pixelShader = CompileShader(pixelShaderPath, GL_PIXEL_SHADER);
    if (pixelShader == 0)
    {
        return 0;
    }
    GLuint programID = glCreateProgram();
    glAttachShader(vertexShader);
    glAttachShader(pixelShader);

    glLinkProgram(programID);

    GLuint error;
    GLuint log_len;
    glGetParameteri(programId, GL_LINK_STATUS, &error);
    glGetParameteri(programId, GL_LOG_INFO_LENGTH, &log_len);
    if (log_len > 0)
    {
        fprintf(stderr, "Cannot link program.\n");
        return 0;
    }
    glDetachShader(vertexShader);
    glDetachShader(pixelShader);
    glDestroyShader(vertexShader);
    glDestroyShader(pixelShader);

    return programId;
}


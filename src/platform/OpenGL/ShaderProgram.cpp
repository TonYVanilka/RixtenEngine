#include "core/AssetSystem/ShaderProgram.h"
#include "core/LogManager.h"

ShaderProgram::ShaderProgram(std::string path) : 
    shaderProgramID(0) {
}

bool ShaderProgram::Load() {
    return false;
}

bool ShaderProgram::LoadD(const char* vertexSS_, const char* fragmentSS_) {

    vertexShaderSource = vertexSS_; 
    fragmentShaderSource = fragmentSS_;

    int success;
    char infoLog[512];

    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        LOG_ERROR("Failed to compile vertex shader: ", infoLog);
        return false;
    }

    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        LOG_ERROR("Failed to compile fragment shader: ", infoLog);
        return false;
    }

    shaderProgramID = glCreateProgram();

    glAttachShader(shaderProgramID, vertexShader);
    glAttachShader(shaderProgramID, fragmentShader);
    glLinkProgram(shaderProgramID);

    glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgramID, 512, NULL, infoLog);
        LOG_ERROR("Failed to compile shader program: ", infoLog);
        return false;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return true;
}

void ShaderProgram::Unload() {
    vertexShaderSource = "";
    fragmentShaderSource = "";
}

void ShaderProgram::Use() {
    glUseProgram(shaderProgramID);
}

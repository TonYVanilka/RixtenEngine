#pragma once
#include <glad/glad.h>

#include <string>

#include "IAsset.h"
#include "core/AssetSystem/IShaderProgram.h"

class ShaderProgram : public IAsset {

public:

    ShaderProgram(std::string path);

    bool Load();
    bool LoadD(const char* vertexSS_, const char* fragmentSS_);
    void Unload(); 

    void Use();

private: 

    GLuint shaderProgramID;
    const GLchar* vertexShaderSource;
    const GLchar* fragmentShaderSource;
};
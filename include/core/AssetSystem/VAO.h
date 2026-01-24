#pragma once
#include "IAsset.h"
#include <glad/glad.h>
#include <string>

class VAO : public IAsset {

public:

    VAO(std::string path);

    bool Load() override;
    void Unload() override;
    void Bind();

private:

    GLuint m_vao;

};
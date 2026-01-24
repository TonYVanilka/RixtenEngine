#pragma once
#include "IAsset.h"
#include <string>
#include <vector>
#include "core/Graphic/Vertex.h"
#include <glad/glad.h>

class Mesh : public IAsset {

public:

    Mesh(std::string path_);
    ~Mesh();

    bool Load() override;
    bool LoadD(std::vector<Vertex>& vertices_, std::vector<uint32_t>& indices_);

    void BindVAO();

    std::vector<Vertex>& GetVertices();
    std::vector<uint32_t>& GetIndices();
    uint32_t GetIndicesCount() const;
    void Unload() override;

private:

    std::string path;
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;

    GLuint VAO;
    GLuint VBO;
    GLuint EBO;

    bool UseIndices;
    uint32_t indicesCount;
};
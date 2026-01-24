#include "core/AssetSystem/Mesh.h"
#include "core/AssetSystem/FileReader.h"

Mesh::Mesh(std::string path_) : 
    path(""), UseIndices(true),
    VBO(0), EBO(0) {
}

Mesh::~Mesh() {
    Unload();
}

bool Mesh::Load() {
    return false;
}

bool Mesh::LoadD(std::vector<Vertex>& vertices_, std::vector<uint32_t>& indices_) {
    vertices = vertices_;
    indices = indices_;
    indicesCount = indices_.size();
    // VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
    if (!indices.empty()) {
        indicesCount = indices.size();

        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesCount * sizeof(uint32_t), indices.data(), GL_STATIC_DRAW);

        UseIndices = true;
    } else {
        indicesCount = 0;
        UseIndices = false;
    }

    // 0: position (vec3)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);

    // 1: texCoords (vec2)
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, textureCords));
    glEnableVertexAttribArray(1);

    // 2: normal (vec3)
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);

    return true;
};

void Mesh::BindVAO() {
    glBindVertexArray(VAO);
}

std::vector<Vertex>& Mesh::GetVertices() {
    return vertices;
}

std::vector<uint32_t>& Mesh::GetIndices() {
    return indices;
}

uint32_t Mesh::GetIndicesCount() const {
    return indicesCount;
}

void Mesh::Unload() {

    if(VAO != 0) {
        glDeleteBuffers(1, &VAO);
        VAO = 0;
    }

    if (VBO != 0) {
        glDeleteBuffers(1, &VBO);
        VBO = 0;
    }

    if (EBO != 0) {
        glDeleteBuffers(1, &EBO);
        EBO = 0;
    }

    path.clear();
    vertices.clear();
    indices.clear();
}

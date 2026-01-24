#include "core/AssetSystem/VAO.h"
#include "core/Graphic/Vertex.h"
#include <cstddef>

VAO::VAO(std::string path) : m_vao(0) {
}

bool VAO::Load() {
    
    glGenBuffers(1, &m_vao);

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
}

void VAO::Unload() {
}

void VAO::Bind() {
    glBindVertexArray(m_vao);
}

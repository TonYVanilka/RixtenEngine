#include "core/AssetSystem/Mesh.h"

Mesh::Mesh(std::string path_) {
}

bool Mesh::Load() {
    return true;
}

std::vector<Vertex>& Mesh::GetVertices() {
    return vertices;
}

std::vector<uint8_t>& Mesh::GetIndces() {
    return indces;
}

uint16_t Mesh::GetIndcesCount() const {
    return indcesCount;
}

void Mesh::Unload() {
}

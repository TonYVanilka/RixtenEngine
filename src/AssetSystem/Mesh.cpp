#include "core/AssetSystem/Mesh.h"
#include "core/AssetSystem/FileReader.h"

Mesh::Mesh(std::string path_) : path(path_), vertices(), indces(), indcesCount(0) {
}

Mesh::~Mesh() {
    Unload();
}

bool Mesh::Load() {return true; }; 

bool Mesh::LoadD(std::vector<Vertex>& vertices_, std::vector<uint32_t> indices_) {

    vertices = vertices_;
    indces = indices_;
    indcesCount = indces.size();
    
    return true;
}

std::vector<Vertex>& Mesh::GetVertices() {
    return vertices;
}

std::vector<uint32_t>& Mesh::GetIndces() {
    return indces;
}

uint32_t Mesh::GetIndcesCount() const {
    return indcesCount;
}

void Mesh::Unload() {
    path.clear();
    vertices.clear();
    indces.clear();
}

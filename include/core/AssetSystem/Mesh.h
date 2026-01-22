#pragma once
#include "IAsset.h"
#include <string>
#include <vector>
#include "Vertex.h"

class Mesh : IAsset {

public:

    Mesh(std::string path_);

    bool Load() override;
    std::vector<Vertex>& GetVertices();
    std::vector<uint8_t>& GetIndces();
    uint32_t GetIndcesCount() const;
    void Unload() override;

private:

    std::string path;
    std::vector<Vertex> vertices;
    std::vector<uint8_t> indces;

    uint32_t indcesCount;

};
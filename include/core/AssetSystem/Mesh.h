#pragma once
#include "IAsset.h"
#include <string>
#include <vector>
#include "Vertex.h"

class Mesh : public IAsset {

public:

    Mesh(std::string path_);
    ~Mesh();

    bool Load() override;
    bool LoadD(std::vector<Vertex>& vertices_, std::vector<uint32_t> indices_);

    std::vector<Vertex>& GetVertices();
    std::vector<uint32_t>& GetIndces();
    uint32_t GetIndcesCount() const;
    void Unload() override;

private:

    std::string path;
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indces;

    uint32_t indcesCount;

};
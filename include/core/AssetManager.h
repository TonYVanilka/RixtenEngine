#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include "IAsset.h"
#include "Shader.h"

class AssetManager {

public:

    AssetManager();
    ~AssetManager();

    void SeeAllAssets() const;

    template<typename T>
    std::shared_ptr<T> GetAsset(std::string& path);

private:

    std::unordered_map<std::string, std::shared_ptr<IAsset>> cache;

};
#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include "IAsset.h"
#include "TextFile.h"

class AssetManager {

public:

    AssetManager();
    ~AssetManager();

    void SeeAllAssets() const;

    template<typename T>
    T* GetAsset(std::string path);

    void DellAsset(std::string path);

    void ShutDown();

private:
    std::unordered_map<std::string, std::unique_ptr<IAsset>> cache;
};
#pragma once

#include <memory>
#include <string>
#include <type_traits>
#include <unordered_map>

#include "IAsset.h"
#include "Mesh.h"
#include "core/AssetSystem/ShaderProgram.h"
#include "TextFile.h"

class AssetManager {

public:

    AssetManager();
    ~AssetManager();

    void SeeAllAssets() const;

    template <typename T>
    T* GetAsset(const std::string& path) {
        static_assert(std::is_base_of_v<IAsset, T>, "T must must be child of IAssets");
        auto it = cache.find(path);
        if (it != cache.end()) {
            return static_cast<T*>(it->second.get());
        }

        auto asset = std::make_unique<T>(path);
        T* raw = asset.get();
        cache[path] = std::move(asset);
        return raw;
    }

    IAsset& newAsset();

    void DellAsset(const char* path);

    void ShutDown();

private:
    std::unordered_map<std::string, std::unique_ptr<IAsset>> cache;
};
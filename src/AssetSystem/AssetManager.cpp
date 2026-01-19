#include "core/AssetManager.h"
#include <fstream> 
#include <string>
#include <iostream>
#include "core/LogManager.h"

AssetManager::AssetManager() {
}

AssetManager::~AssetManager() {
}

void AssetManager::SeeAllAssets() const {
    for (const auto& element : cache) {
        LOG_DEBUG(element.first);
    }
}

template<>
std::shared_ptr<Shader> AssetManager::GetAsset<Shader>(std::string& path) {
    
    auto it = cache.find(path);
    if (it != cache.end()) {
        return std::static_pointer_cast<Shader>(it->second);
    }

    auto shader = std::make_shared<Shader>(path);

    cache[path] = shader;

    return std::shared_ptr<Shader>();
}
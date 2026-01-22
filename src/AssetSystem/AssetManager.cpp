#include "core/AssetSystem/AssetManager.h"
#include <fstream> 
#include <string>
#include <iostream>
#include "core/LogManager.h"

AssetManager::AssetManager() {
}

AssetManager::~AssetManager() {
}

void AssetManager::SeeAllAssets() const {
    if (cache.empty()) {LOG_INFO("No one asset"); return;}
    for (const auto& element : cache) {
        LOG_INFO(element.first);
    }
}

template <>
TextFile* AssetManager::GetAsset<TextFile>(std::string path) {
    auto it = cache.find(path);
    if (it != cache.end()) {
        return static_cast<TextFile*>(it->second.get());
    }
    
    auto asset = std::make_unique<TextFile>(path);
    TextFile* raw = asset.get();

    cache.emplace(path, std::move(asset));
    return raw;
}

template <>
Mesh* AssetManager::GetAsset<Mesh>(std::string path) {
    auto it = cache.find(path);
    if (it != cache.end()) {
        return static_cast<Mesh*>(it->second.get());
    }

    auto asset = std::make_unique<Mesh>(path);
    Mesh* raw = asset.get();

    cache.emplace(path, std::move(asset));
    return raw;
}

void AssetManager::DellAsset(std::string path) {
    auto it = cache.find(path);
    if(it != cache.end()) {
        cache.erase(path);
        return;
    }
    LOG_ERROR("Asset is not exist");
}
void AssetManager::ShutDown() {
    if (cache.empty()) return;
    cache.clear();
}
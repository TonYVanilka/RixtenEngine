#include "core/AssetSystem/AssetManager.h"

#include <fstream>
#include <iostream>
#include <string>

#include "utils/Logger.h"

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

void AssetManager::DellAsset(const char* path) {
    std::string strPath(path);
    if (cache.erase(strPath) == 0) {
        LOG_ERROR("Asset does not exist: " + strPath);
    }
}

void AssetManager::ShutDown() {
    if (cache.empty()) return;
    cache.clear();
}
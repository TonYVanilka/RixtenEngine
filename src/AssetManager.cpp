#include "core/AssetManager.h"
#include <fstream> 
#include <string>
#include <iostream>

AssetManager::AssetManager() {
}

AssetManager::~AssetManager() {
}

const char* AssetManager::GetFile(const char* path) {

    std::fstream file(path);

    if(!file.is_open()) {
        return nullptr;
    }

    file.seekg(0, std::ios::end);
    size_t fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Читаем весь файл
    std::string fileSource(fileSize, '\0');
    file.read(fileSource.data(), fileSize);

    const char* result = fileSource.c_str();

    return result;
}
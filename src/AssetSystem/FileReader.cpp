#include "core/AssetSystem/FileReader.h"
#include <fstream>
#include "core/LogManager.h"

bool FileSystem::ReadFileBinary(const std::string& path, std::vector<std::byte>& outData) {
    
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if(!file) {
        LOG_ERROR("Failed to open file: ", path);
        return false;
    }
    
    const auto size = file.tellg();
    outData.resize(static_cast<size_t>(size));

    file.seekg(0);
    file.read(reinterpret_cast<char*>(outData.data()), size);

    return true;
}
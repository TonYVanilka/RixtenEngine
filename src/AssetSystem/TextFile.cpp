#include "core/AssetSystem/TextFile.h"
#include "core/AssetSystem/FileReader.h"
#include "utils/Logger.h"

TextFile::TextFile(std::string path_) : path(path_), data("") {
}

TextFile::~TextFile() {
    Unload();
}

bool TextFile::Load() {
    std::vector<std::byte> raw;

    if (!FileSystem::ReadFileBinary(path, raw)) return false;

    data.assign(reinterpret_cast<const char*>(raw.data()), raw.size());
    
    return true;
}

const char* TextFile::GetData() const {
    if (data.empty()) {
        LOG_ERROR("Data is empty!");
        return "";
    }
    return data.c_str();
}

void TextFile::Unload() {
    path.clear();
    data.clear();
}
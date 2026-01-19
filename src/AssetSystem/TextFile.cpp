#include "core/TextFile.h"
#include <fstream>
#include "core/LogManager.h"

TextFile::TextFile(std::string path_) : path(path_), data() {
    LOG_DEBUG("TextFile constructor called for: " + path_);
}

bool TextFile::Load() {

    std::ifstream file(path, std::ios::binary);

    if(!file.is_open()) { 
        LOG_ERROR("Asset manager: Shader: Failed to open file");
        return false;
    }

    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    data.resize(size);
    file.read(&data[0], size);

    file.close();
    return true;
}

const char* TextFile::GetData() {
    if (data.empty()) {
        LOG_ERROR("Shader data is empty!");
        return "";
    }
    return data.c_str();
}

void TextFile::Unload() {
}

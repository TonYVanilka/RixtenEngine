#include "core/Shader.h"
#include <fstream>
#include "core/LogManager.h"

Shader::Shader(std::string path_) : path(path_) {
}

bool Shader::Load(const char* path_) {
    path = path_;

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

const char* Shader::GetData() {
    return data.c_str();
}

void Shader::Unload() {
}

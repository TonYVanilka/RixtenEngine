#pragma once
#include "IAsset.h"
#include <string>

class Shader: public IAsset {

public:

    Shader(std::string path_);

    bool Load(const char* path_) override;
    const char* GetData();
    void Unload() override;

private:    

    std::string path;
    std::string data;

};
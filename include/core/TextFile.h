#pragma once
#include "IAsset.h"
#include <string>

class TextFile: public IAsset {

public:

    TextFile(std::string path_);

    bool Load() override;
    const char* GetData();
    void Unload() override;

private:    

    std::string path;
    std::string data;

};
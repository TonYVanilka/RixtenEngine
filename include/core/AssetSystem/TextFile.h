#pragma once
#include "IAsset.h"
#include <string>

class TextFile: public IAsset {

public:

    TextFile(std::string path_);
    ~TextFile();

    bool Load() override;
    const char* GetData() const;
    void Unload() override;

private:    

    std::string path;
    std::string data;

};
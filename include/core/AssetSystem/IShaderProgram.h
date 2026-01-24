#pragma once
#include "IAsset.h"

class IShaderProgram : public IAsset {

public: 

    ~IShaderProgram() = default;

    virtual bool Load() = 0;
    virtual void Unload() = 0;

    virtual void Use() = 0;

};
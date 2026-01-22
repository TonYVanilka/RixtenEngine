#pragma once

#include "core/AssetSystem/AssetManager.h"

class IRenderer {

public:

    ~IRenderer() = default;

    virtual bool Init(AssetManager* assetManaget) = 0;
    virtual void ShutDown() = 0;

    virtual void AddToRender() = 0;
    virtual void RemoveFromRender() = 0;
    
    virtual void Render() = 0;

};
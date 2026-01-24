#pragma once

#include "core/AssetSystem/AssetManager.h"

class IRenderer {

public:

    virtual ~IRenderer() = default;

    virtual bool Init(AssetManager* assetManaget) = 0;
    virtual void ShutDown() = 0;

    virtual void AddToRender() = 0;
    virtual void RemoveFromRender() = 0;    

private: 

    virtual void beginFrame() = 0;
    virtual void endFrame() = 0;
    virtual void renderCommand() = 0;

};
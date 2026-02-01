#pragma once

#include "core/AssetSystem/IShaderProgram.h"
#include "core/AssetSystem/VAO.h"

class IRenderState {

public:

    virtual ~IRenderState() = default;

    virtual void SetShaderProgram(IShaderProgram* currentSP_) = 0;
    virtual void SetVAO(VAO* currentVAO_) = 0;

    virtual IShaderProgram* GetShaderProgram() const = 0;
    virtual VAO* GetVAO() const = 0;

}; 
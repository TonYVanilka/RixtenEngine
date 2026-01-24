#pragma once
#include <cstdint>

#include "core/AssetSystem/ShaderProgram.h"
#include "core/Graphic/IRenderState.h"

class RenderState {

public: 

    RenderState();

    void SetShaderProgram(ShaderProgram* currentSP_);
    void SetVAO(VAO* currentVAO_);

    void Reset();

    ShaderProgram* GetShaderProgram() const;
    VAO* GetVAO() const;

    uint32_t countDrawCalls;
    uint32_t countTriangels;

    uint32_t curentTexturesSlots[16];

   private: 

    ShaderProgram* currentShaderProgram;
    VAO* currentVAO;

};
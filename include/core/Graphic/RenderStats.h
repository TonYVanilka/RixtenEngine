#pragma once
#include <cstdint>

#include "core/AssetSystem/ShaderProgram.h"
#include "core/Graphic/IRenderStats.h"

class RenderStats {

public: 

    RenderStats();
    ~RenderStats();

    void BindShaderProgram(ShaderProgram* currentSP_);
    void BindVAO(VAO* currentVAO_);

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
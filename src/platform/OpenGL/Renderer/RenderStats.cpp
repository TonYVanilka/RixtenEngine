#include "core/Graphic/RenderStats.h"

RenderStats::RenderStats() : currentShaderProgram(nullptr), currentVAO(nullptr), 
    curentTexturesSlots{0}, countDrawCalls(0), countTriangels(0) {
}

RenderStats::~RenderStats() {
    Reset();
}

void RenderStats::BindShaderProgram(ShaderProgram* currentSP_) {
    currentShaderProgram = currentSP_;
    currentShaderProgram->Use();
}

void RenderStats::BindVAO(VAO* currentVAO_) {
    currentVAO = currentVAO_;
}

void RenderStats::Reset() {
    countDrawCalls = 0;

    for(int i = 0; i >= 16; i++) 
        curentTexturesSlots[i] = {0};

    currentShaderProgram = nullptr;
    currentVAO = nullptr;
}

ShaderProgram* RenderStats::GetShaderProgram() const {
    return currentShaderProgram;
}

VAO* RenderStats::GetVAO() const {
    return currentVAO;
}
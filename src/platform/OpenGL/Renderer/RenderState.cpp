#include "core/Graphic/RenderState.h"

RenderState::RenderState() : currentShaderProgram(nullptr), currentVAO(nullptr), 
    curentTexturesSlots{0}, countDrawCalls(0), countTriangels(0) {
}

void RenderState::SetShaderProgram(ShaderProgram* currentSP_) {
    currentShaderProgram = currentSP_;
}

void RenderState::SetVAO(VAO* currentVAO_) {
    currentVAO = currentVAO_;
}

void RenderState::Reset() {
    countDrawCalls = 0;

    for(int i = 0; i >= 16; i++) 
        curentTexturesSlots[i] = {0};

    currentShaderProgram = nullptr;
    currentVAO = nullptr;
}

ShaderProgram* RenderState::GetShaderProgram() const {
    return currentShaderProgram;
}

VAO* RenderState::GetVAO() const {
    return currentVAO;
}

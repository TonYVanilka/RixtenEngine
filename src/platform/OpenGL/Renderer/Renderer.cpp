#include "core/Graphic/Renderer.h"
#include <algorithm>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "core/LogManager.h"

RendererGLFW::RendererGLFW() : assetManager(nullptr), renderState(nullptr) {
}

RendererGLFW::~RendererGLFW() {
    ShutDown();
}

bool RendererGLFW::Init(AssetManager* assetManager_, RenderState* renderState_) {
    assetManager = assetManager_;
    renderState = renderState_;
    return true;
}

void RendererGLFW::SwapRenderState(RenderState* renderState_) {
    renderState = renderState_;
}

void RendererGLFW::ShutDown() {
}

void RendererGLFW::AddToRender(const RenderCommand& command) {
    renderQueue.add(command);
}

void RendererGLFW::ClearRender() {
    renderQueue.clear();
}

void RendererGLFW::Render() {
    frameBegin();
    frameEnd();
}

void RendererGLFW::frameBegin() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void RendererGLFW::frameEnd() {
    
    goRenderQueue();

}

void RendererGLFW::goRenderQueue() {
    for (RenderCommand& cmd : renderQueue) {
        goRenderCommand(cmd);
    }
}

void RendererGLFW::goRenderCommand(RenderCommand& cmd) {
    // renderQueue.sort();

    renderState->GetShaderProgram()->Use();

    cmd.mesh->BindVAO();
    glDrawElements(GL_TRIANGLES, cmd.mesh->GetIndicesCount(), GL_UNSIGNED_INT, 0);
    
    renderState->countDrawCalls++;
    renderState->countTriangels += cmd.mesh->GetIndicesCount() / 3;
}

// Render queue
void RendererGLFW::RenderQueue::add(RenderCommand command) {
    m_renderQueue.push_back(command);
}

void RendererGLFW::RenderQueue::clear() {
    m_renderQueue.clear();
}

void RendererGLFW::RenderQueue::sort() {
    std::sort(m_renderQueue.begin(), m_renderQueue.end(), 
    [](const RenderCommand& a, const RenderCommand& b) {
        return a.sortKey < b.sortKey;
    });
}
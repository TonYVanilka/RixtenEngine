#include "core/Graphic/Renderer.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <algorithm>

#include "utils/Logger.h"

RendererGLFW::RendererGLFW() : assetManager(nullptr), m_Stats(nullptr) {
}

RendererGLFW::~RendererGLFW() {
    ShutDown();
}

bool RendererGLFW::Init(AssetManager* assetManager_, RenderStats* stats_) {
    assetManager = assetManager_;
    m_Stats = stats_;
    return true;
}

void RendererGLFW::SwapRenderState(RenderStats* stats_) {
    m_Stats = stats_;
}

void RendererGLFW::ShutDown() {
}

void RendererGLFW::Submit(const RenderCommand& command) {
    m_Queue.add(command);
}

void RendererGLFW::ClearRender() {
    m_Queue.clear();
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
    renderQueue();
}

void RendererGLFW::renderQueue() {
    for (RenderCommand& cmd : m_Queue) {
        doRenderCommand(cmd);
    }
}

void RendererGLFW::doRenderCommand(RenderCommand& cmd) {
    // renderQueue.sort();

    m_Stats->GetShaderProgram()->Use();

    cmd.mesh->BindVAO();
    glDrawElements(GL_TRIANGLES, cmd.mesh->GetIndicesCount(), GL_UNSIGNED_INT, 0);
    
    m_Stats->countDrawCalls++;
    m_Stats->countTriangels += cmd.mesh->GetIndicesCount() / 3;
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
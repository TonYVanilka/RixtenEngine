#include "Renderer.h"

RendererGLFW::RendererGLFW() : assetManager(nullptr) {
}

RendererGLFW::~RendererGLFW() {
    ShutDown();
}

bool RendererGLFW::Init(AssetManager* assetManaget) {
    return false;
}

void RendererGLFW::ShutDown() {
}

void RendererGLFW::AddToRender() {
}

void RendererGLFW::RemoveFromRender() {
}

void RendererGLFW::Render() {
}
#include "core/Graphic/IRenderer.h"
#include <vector>

struct RenderCommand {

    Mesh* mesh;

};

struct RenderQueue {

public:

    void Sort();

private:

    std::vector<RenderCommand> m_renderQueue;

};

class RendererGLFW : public IRenderer {

public:

    RendererGLFW();
    ~RendererGLFW();

    bool Init(AssetManager* assetManaget);
    void ShutDown();

    void AddToRender();
    void RemoveFromRender();
    
    void Render();

private:

    std::vector<> renderQueue;
    AssetManager* assetManager;

};
#include <vector>

#include "core/AssetSystem/ShaderProgram.h"
#include "core/AssetSystem/VAO.h"
#include "core/Graphic/IRenderer.h"
#include "RenderStats.h"

struct RenderCommand {
    uint64_t sortKey;
    Mesh* mesh;
};

class RendererGLFW{

public:

    RendererGLFW();
    ~RendererGLFW();

    bool Init(AssetManager* assetManager_, RenderStats* stats_);

    void SwapRenderState(RenderStats* stats_);

    void ShutDown();

    void Submit(const RenderCommand& command);
    void ClearRender();

    void Render();

private:

    void frameBegin();
    void frameEnd();
    
    // Render queue
    struct RenderQueue {

    public:

        void add(RenderCommand command);

        void clear();
        void sort();

        auto begin() { return m_renderQueue.begin(); }
        auto end() { return m_renderQueue.end(); }
        auto begin() const { return m_renderQueue.begin(); }
        auto end() const { return m_renderQueue.end(); }

    private:

        std::vector<RenderCommand> m_renderQueue;
    };

    void renderQueue();
    void doRenderCommand(RenderCommand& cmd);

    RenderStats* m_Stats;
    RenderQueue m_Queue;
    AssetManager* assetManager;

};
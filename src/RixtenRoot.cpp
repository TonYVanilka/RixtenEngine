#include "RixtenRoot.h"
#include <string>
#include <iostream>
#include "scripting/bindings/luaWindow.h"
#include <exception>
#include "core/Graphic/Vertex.h"
#include "utils/Logger.h"

std::vector<Vertex> vertices =
    {
        // position              textureCords       normal
        {{-0.5f, -0.5f, 0.0f}, {0.5f, 0.0f}, {0.5f, 0.0f, 0.0f}},
        {{0.5f, -0.5f, 0.0f}, {0.5f, 0.0f}, {0.5f, 0.0f, 0.0f}},
        {{0.0f, 0.5f, 0.0f}, {0.5f, 0.0f}, {0.5f, 0.0f, 0.0f}}
	};

std::vector<uint32_t> indices = {0, 1, 2};

RixtenRoot::RixtenRoot() : window(nullptr), lua(nullptr), assetManager(nullptr) {
}

RixtenRoot::~RixtenRoot() {
	ShutDown();
	LOG_INFO("=== Rixten sccsefuly destroy ===");
}

bool RixtenRoot::Init() {

    static LoggerState logger;
    logger.logLevel = LogLevel::DEBUG;

    Logger::Init(logger, "engine.log");

    g_logger = &logger;

    LOG_DEBUG("HELLO FROM DOD LOGGER");

    // Logger
    //Logger::GetInstance();
    // Logger::GetInstance().SetOnlyOneType(TypeMessage::ERROR);
    //Logger::GetInstance().SetLoggerLayer(TypeMessage::ERROR);
 
    LOG_INFO("=== Rixten start Init ===");

    // Asset manager
    assetManager = new AssetManager();
    // TextFile* luaMain = assetManager->GetAsset<TextFile>("main.lua");
    // luaMain->Load();
    // LOG_DEBUG(luaMain->GetData());

    // std::vector<Vertex> vr = triangle->GetVertices();
    // for (int i = 0; i < vr.size(); i++) {
    // 	LOG_DEBUG(*vr[i].position);
    // }

    // int* a = assetManager->GetAsset<int>("dd");
    // Lua
    lua.open_libraries(sol::lib::base, sol::lib::math);

    // window
    window = CreateRixtenWindow(800, 600, "RixtenEngine window");
    if (!window->Init()) return false;

    // shaders
    TextFile* vert = assetManager->GetAsset<TextFile>("assets/shaders/vertex.glsl");
    vert->Load();
    TextFile* frag = assetManager->GetAsset<TextFile>("assets/shaders/fragment.glsl");
    frag->Load();
    // shader programm
    ShaderProgram* shaderProg = assetManager->GetAsset<ShaderProgram>("shaderProg");
    shaderProg->LoadD(vert->GetData(), frag->GetData());

    Mesh* triangle = assetManager->GetAsset<Mesh>("main.lua");
    triangle->LoadD(vertices, indices);

    renderState = new RenderStats();
    renderState->BindShaderProgram(shaderProg);
	renderer = new RendererGLFW();
    renderer->Init(assetManager, renderState);
    renderer->Submit({1, triangle});

    LOG_INFO("=== Rixten successfully Init ===");

    return true;
}

void RixtenRoot::ShutDown() {
	if (window) {
		window->ShutDown();
		delete window;
		window = nullptr;
	}
	if (assetManager) {
		assetManager->ShutDown();
		delete assetManager;
		assetManager = nullptr;
	} 
	LOG_INFO("Shut down Rixten");
    Logger::ShutDown(*g_logger);
}

void RixtenRoot::RegisterBindings() {
    RegisterWindow(lua, this);
}

void RixtenRoot::LoadScript() {
	lua.script_file("main.lua");
}

void RixtenRoot::RunEngine() {

	int deltaTime = 0;

	RegisterBindings();
    LoadScript();
    lua["on_init"]();

    while (!window->IsOpen()) {
        lua["on_tick"](deltaTime);
        renderer->Render();
    }

}

IWindow* RixtenRoot::GetWindow() {return window;}
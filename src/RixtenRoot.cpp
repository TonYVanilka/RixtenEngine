#include "RixtenRoot.h"
#include <string>

#include "scripting/bindings/luaWindow.h"

RixtenRoot::RixtenRoot() : window(nullptr), lua(nullptr), assetManager(nullptr) {
}

RixtenRoot::~RixtenRoot() {
	ShutDown();
	LOG_INFO("=== Rixten sccsefuly destroy ===");
}

bool RixtenRoot::Init() {

	// Logger
	Logger::GetInstance();

	LOG_INFO("=== Rixten start Init ===");

	// Asset manager
	assetManager = new AssetManager();

	std::cout << assetManager->GetFile("main.lua") << std::endl;

    // Lua
    lua.open_libraries(sol::lib::base, sol::lib::math);

    // window
    window = CreateRixtenWindow(800, 600, "RixtenEngine window");
    if (!window->Init()) return false;

    LOG_INFO("=== Rixten successfully Init ===");

    return true;
}

void RixtenRoot::ShutDown() {
	if (window) {
		window->ShutDown();
		delete window;
		window = nullptr;
	}
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
    }

	ShutDown();

}

IWindow* RixtenRoot::GetWindow() {return window;}
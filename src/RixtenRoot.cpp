#include "RixtenRoot.h"
#include <iostream>
#include <string>

#include "scripting/bindings/luaWindow.h"

RixtenRoot::RixtenRoot() : window(nullptr), lua(nullptr) {
}

RixtenRoot::~RixtenRoot() {
	ShutDown();
	std::cout << "Rixten sescefuly destroy!" << std::endl;
}

bool RixtenRoot::Init() {

	// Lua
    lua.open_libraries(sol::lib::base, sol::lib::math);

    // window
	window = CreateRixtenWindow(800, 600, "RixtenEngine window");
	if(!window->Init()) return false;

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

void RixtenRoot::RunEngine() {
	std::cout << "=== Rixten Engine run ===" << std::endl;

	RegisterBindings();

    lua.script_file("main.lua");
}

IWindow* RixtenRoot::GetWindow() {return window;}
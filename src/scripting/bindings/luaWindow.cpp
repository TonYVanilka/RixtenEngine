#include "luaWindow.h"
#include "RixtenRoot.h"
#include "core/IWindow.h"

void RegisterWindow(sol::state& lua, RixtenRoot* engine) {
    lua.new_usertype<IWindow>(
        "Window",
        "update", &IWindow::Update,
        "is_open", &IWindow::IsWindow
    );

    lua["RixtenEngine"] = lua.create_table();

    lua["RixtenEngine"]["create_window"] =
        [engine](int w, int h, const char* title) {
            return engine->GetWindow();
        };
}
#include "luaWindow.h"
#include "RixtenRoot.h"
#include "core/IWindow.h"

void RegisterWindow(sol::state& lua, RixtenRoot* engine) {
    lua.new_usertype<IWindow>(
        "Window",
        "update", &IWindow::Update,
        "is_open", &IWindow::IsOpen,
        "set_size", &IWindow::SetSize,
        "set_title", &IWindow::SetTitle
    );

    lua["RixtenEngine"] = lua.create_table();

    lua["RixtenEngine"]["create_window"] =
        [engine](int width, int height, const char* title) {
            IWindow* my_win = engine->GetWindow();
            my_win->SetSize(width, height);
            my_win->SetTitle(title);
            return my_win;
        };
}
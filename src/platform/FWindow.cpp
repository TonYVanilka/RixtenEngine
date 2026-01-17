#include "core/Window.h"

#ifdef _WIN32
#include "OpenGL/Window.h"
#endif

IWindow* CreateRixtenWindow(int width, int height, const char* title) {
#ifdef _WIN32
    return new Window(width, height, title);
#else
    return nullptr;
#endif  // _WIN32
}
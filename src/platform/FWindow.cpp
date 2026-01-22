#include "core/Window.h"

#ifdef RIXTEN_USE_OPENGL
#include "OpenGL/Window.h"
#endif

IWindow* CreateRixtenWindow(int width, int height, const char* title) {
#ifdef RIXTEN_USE_OPENGL
    return new Window(width, height, title);
#else
    return nullptr;
#endif  // RIXTEN_USE_OPENGL
}
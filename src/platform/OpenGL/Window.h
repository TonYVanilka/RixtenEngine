#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "core/IWindow.h"

class Window : public IWindow {

public:
    Window(int width_, int height_, const char* title_);
    ~Window();

    bool Init() override;
    void ShutDown() override;

    bool IsWindow() const override;
    void Update() override;

private:

    int width;
    int height;
    const char* title;

    GLFWwindow* handle;

};
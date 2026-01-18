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

    bool IsOpen() const override;
    void Update() override;

    void SetSize(int width, int height) override;
    void SetTitle(const char* title_) override;

private:

    int width;
    int height;
    const char* title;

    GLFWwindow* handle;

};
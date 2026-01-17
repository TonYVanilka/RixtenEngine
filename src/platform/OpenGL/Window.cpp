#include "Window.h"
#include <iostream>

Window::Window(int width_, int height_, const char* title_) : width(width_), height(height_), title(title_), handle(nullptr) {
}

Window::~Window() {
    ShutDown();
}

bool Window::Init() {

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  // comment after first run

    handle = glfwCreateWindow(width, height, title, NULL, NULL);

    if(handle == nullptr) {
        std::cout << "failed to init opengl window" << std::endl;
        return false;
        ShutDown();
    }

    glfwMakeContextCurrent(handle);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
        Window::ShutDown();
    }

    return true;
}

void Window::ShutDown() {
    glfwTerminate();
}

bool Window::IsWindow() const {
    return glfwWindowShouldClose(handle);
}

void Window::Update() {
    glfwSwapBuffers(handle);
    glfwPollEvents();
    // a temporary solution
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
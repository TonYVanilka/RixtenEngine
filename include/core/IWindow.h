#pragma once

class IWindow {

public:

    virtual ~IWindow() = default;

    virtual bool Init() = 0;
    virtual void ShutDown() = 0;

    virtual bool IsOpen() const = 0;
    virtual void Update() = 0;

    virtual void SetSize(int width, int height) = 0;
    virtual void SetTitle(const char* title) = 0;
};
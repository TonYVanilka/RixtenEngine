#pragma once

class IWindow {
   public:
    ~IWindow() = default;

    virtual bool Init() = 0;
    virtual void ShutDown() = 0;

    virtual bool IsWindow() const = 0;
    virtual void Update() = 0;
};
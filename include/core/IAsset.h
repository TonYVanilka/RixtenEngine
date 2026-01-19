#pragma once

class IAsset {

public:

    ~IAsset() = default;

    virtual bool Load() = 0;
    virtual void Unload() = 0;

private:

}; 
#pragma once

class IAsset {

public:

    virtual ~IAsset() = default;

    virtual bool Load() = 0;
    virtual void Unload() = 0;

}; 
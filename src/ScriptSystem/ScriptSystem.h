#pragma once
#include <lua.hpp>

class ScriptSystem {

public:

    ScriptSystem();
    ~ScriptSystem();

    bool Init();
    void ShutDown();

    int DoString(const char* script);

private:

    lua_State* L;

};
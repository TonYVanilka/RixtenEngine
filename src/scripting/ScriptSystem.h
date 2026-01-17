#pragma once
#include <lua.hpp>

class ScriptSystem {

public:

    ScriptSystem();
    ~ScriptSystem();

    bool Init();
    void ShutDown();

    int DoString(const char* script);
    int DoFile(const char* path);

    template<typename T>
    T GetArg(int index);

    template <typename T>
    void RegisterArg(T value, const char* name);

    template<typename T>
    void Return(T value);

    int GetArgCount() const;

private :

    lua_State *L;
};
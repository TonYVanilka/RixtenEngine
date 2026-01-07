#include "ScriptSystem.h"

ScriptSystem::ScriptSystem() : L(nullptr) {
}

ScriptSystem::~ScriptSystem() {
    ShutDown();
}

bool ScriptSystem::Init() {
    L = luaL_newstate();
    if (!L) return false;
    // open Lua libraries
    luaL_openlibs(L);
    return true;
}

void ScriptSystem::ShutDown() {
    lua_close(L);
}

int ScriptSystem::DoString(const char *script) {
    luaL_dostring(L, script);
    return lua_gettop(L);
}

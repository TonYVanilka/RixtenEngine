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

int ScriptSystem::DoFile(const char *path) {
    int resoult = luaL_dofile(L, path);

    if (resoult != LUA_OK) {
        lua_pop(L, 1);
        return -1;
    }
    return lua_gettop(L);
}

int ScriptSystem::GetArgCount() const {
    return lua_gettop(L);
}

// Get argumenst functions ====================

template <>
int ScriptSystem::GetArg<int>(int index) {
    return lua_tointeger(L, index);
}

template <>
double ScriptSystem::GetArg<double>(int index) {
    return lua_tointeger(L, index);
}

template <>
bool ScriptSystem::GetArg<bool>(int index) {
    return lua_toboolean(L, index);
}

template <>
const char *ScriptSystem::GetArg<const char *>(int index) {
    return lua_tostring(L, index);
}

// Get argumenst functions ====================
// Register argument function =================

template <>
void ScriptSystem::RegisterArg<int>(int value, const char *name) {
    lua_pushinteger(L, value);
    lua_setglobal(L, name);
}

template <>
void ScriptSystem::RegisterArg<double>(double value, const char *name) {
    lua_pushinteger(L, value);
    lua_setglobal(L, name);
}

template <>
void ScriptSystem::RegisterArg<bool>(bool value, const char *name) {
    lua_pushinteger(L, value);
    lua_setglobal(L, name);
}

template <>
void ScriptSystem::RegisterArg<lua_CFunction>(lua_CFunction value, const char *name) {
    lua_pushcfunction(L, value);
    lua_setglobal(L, name);
}

// Register argument function =================
// Return values ==============================

template <>
void ScriptSystem::Return<int>(int value) {
    lua_pushinteger(L, value);
}

template <>
void ScriptSystem::Return<double>(double value) {
    lua_pushinteger(L, value);
}

template <>
void ScriptSystem::Return<bool>(bool value) {
    lua_pushboolean(L, value);
}

template <>
void ScriptSystem::Return<const char *>(const char *value) {
    lua_pushfstring(L, value);
}

// Return values ==============================
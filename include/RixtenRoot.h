#pragma once
#include <sol/sol.hpp>
#include "core/Window.h"
#include "core/AssetSystem/AssetManager.h"
#include "core/Graphic/Renderer.h"
#include "core/Graphic/RenderStats.h"

class RixtenRoot {

public:

	RixtenRoot();
	~RixtenRoot();

	bool Init();
	void ShutDown();

	void LoadScript();

	void RunEngine();

	IWindow* GetWindow();

private:

	void RegisterBindings();

	RenderStats* renderState;
	RendererGLFW* renderer;

	AssetManager* assetManager;
	sol::state lua;
	IWindow* window;

};
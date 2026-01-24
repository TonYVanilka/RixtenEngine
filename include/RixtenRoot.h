#pragma once
#include <sol/sol.hpp>
#include "core/Window.h"
#include "core/AssetSystem/AssetManager.h"
#include "core/LogManager.h"
#include "core/Graphic/Renderer.h"
#include "core/Graphic/RenderState.h"

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

	RenderState* renderState;
	RendererGLFW* renderer;

	AssetManager* assetManager;
	sol::state lua;
	IWindow* window;

};
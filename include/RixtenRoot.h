#pragma once
#include <sol/sol.hpp>
#include "core/Window.h"

class RixtenRoot {

public:

	RixtenRoot();
	~RixtenRoot();

	bool Init();
	void ShutDown();

	void RegisterBindings();

	void RunEngine();

	IWindow* GetWindow();

private:

	sol::state lua;
	IWindow* window;

};
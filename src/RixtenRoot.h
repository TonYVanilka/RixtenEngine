#pragma once 
#include "ScriptSystem/ScriptSystem.h"

class RixtenRoot {

public:

	RixtenRoot();
	~RixtenRoot();

	bool Init();
	void ShutDown();

	void RunEngine();

	int GetInt(int a, int b);

private:

	ScriptSystem* scriptSystem;

};
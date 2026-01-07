#include "RixtenRoot.h"
#include <iostream>

RixtenRoot::RixtenRoot() : scriptSystem(nullptr) {
	std::cout << "Rixten secsefuly created!" << std::endl;
}

RixtenRoot::~RixtenRoot() {
	ShutDown();
	std::cout << "Rixten sescefuly destroy!" << std::endl;
}

bool RixtenRoot::Init() {
	scriptSystem = new ScriptSystem();

	if(!scriptSystem->Init()) return false;

    return true;
}

void RixtenRoot::ShutDown() {
	if (scriptSystem) {
		scriptSystem->ShutDown();
		delete scriptSystem;
		scriptSystem = nullptr;
	}
}

void RixtenRoot::RunEngine() {
	scriptSystem->DoString("print(0123456789)");
	scriptSystem->DoFile("main.lua");
}

int RixtenRoot::GetInt(int a, int b) {
	return a + b;
}
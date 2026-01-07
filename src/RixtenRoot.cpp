#include "RixtenRoot.h"
#include <iostream>

RixtenRoot::RixtenRoot() {
	std::cout << "Rixten secsefuly created!" << std::endl;
}

RixtenRoot::~RixtenRoot() {
	std::cout << "Rixten sescefuly destroy!" << std::endl;
}

int RixtenRoot::GetInt(int a, int b) {
	return a + b;
}
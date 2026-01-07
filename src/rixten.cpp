#include "rixten.h"
#include "RixtenRoot.h"
#include <iostream>

extern "C" {

	RIXTEN_API RixtenEngine CreateEngine() {
		std::cout << "Create Engine" << std::endl;
		return new RixtenRoot();
	}

	RIXTEN_API void DestroyEngine(RixtenEngine  engine) {
		delete static_cast<RixtenRoot*>(engine);
	}

	RIXTEN_API int GetInt(int a, int b, RixtenEngine engine) {
		return static_cast<RixtenRoot*>(engine)->GetInt(a, b);
	}


} // extern "C"
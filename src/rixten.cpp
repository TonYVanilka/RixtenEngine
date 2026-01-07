#include "rixten.h"
#include "RixtenRoot.h"
#include <iostream>


extern "C" {

	RIXTEN_API RixtenEngine CreateEngine() {
		std::cout << "Create Engine" << std::endl;
		return new RixtenRoot();
	}

	RIXTEN_API void DestroyEngine(RixtenEngine  engine) {
		static_cast<RixtenRoot *>(engine)->ShutDown();
		delete static_cast<RixtenRoot *>(engine);
	}

	RIXTEN_API int GetInt(int a, int b, RixtenEngine engine) {
		return static_cast<RixtenRoot*>(engine)->GetInt(a, b);
	}

	RIXTEN_API bool InitEngine(RixtenEngine engine)	{
		return static_cast<RixtenRoot *>(engine)->Init();
	}

    RIXTEN_API void RunEngine(RixtenEngine engine) {
		static_cast<RixtenRoot *>(engine)->RunEngine();
	}

} // extern "C"
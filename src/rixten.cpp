#include "rixten.h"
#include "RixtenRoot.h"

extern "C" {

	RIXTEN_API RixtenEngine CreateEngine() {
		return new RixtenRoot();
	}

	RIXTEN_API void DestroyEngine(RixtenEngine  engine) {
		static_cast<RixtenRoot *>(engine)->ShutDown();
		delete static_cast<RixtenRoot *>(engine);
	}

	RIXTEN_API bool InitEngine(RixtenEngine engine)	{
		return static_cast<RixtenRoot *>(engine)->Init();
	}

    RIXTEN_API void RunEngine(RixtenEngine engine) {
		static_cast<RixtenRoot *>(engine)->RunEngine();
	}

} // extern "C"
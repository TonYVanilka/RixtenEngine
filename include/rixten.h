#pragma once 

#include "api.h"

extern "C" {

	// handles
	typedef void* RixtenEngine;

	//  == Engine Api ==
	RIXTEN_API RixtenEngine CreateEngine();
	RIXTEN_API void DestroyEngine(RixtenEngine engine);
	RIXTEN_API int GetInt(int a, int b, RixtenEngine engine);
	RIXTEN_API bool InitEngine(RixtenEngine engine);
	RIXTEN_API void RunEngine(RixtenEngine engine);
}
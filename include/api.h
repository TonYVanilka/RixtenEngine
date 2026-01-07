#pragma once

#ifdef _WIN32

	#ifdef RIXTEN_EXPORTS
		#define RIXTEN_API __declspec(dllexport)
	#else
		#define RIXTEN_API __declspec(dllimport)
	#endif // RIXTEN_EXPORTS

#else
	#define RIXTEN_API
#endif // _WIN32

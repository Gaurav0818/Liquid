#pragma once

#ifdef LQD_PLATFORM_WINDOWS
	#ifdef LQD_BUILD_DLL
		#define LIQUID_API __declspec(dllexport)
	#else
		#define LIQUID_API __declspec(dllimport)
	#endif
#else
	#error Liquid only supports Windows!
#endif 


#define BIT(x) (1 << x)
#pragma once

#ifdef LQD_PLATFORM_WINDOWS
	#ifdef LQD_BUILD_DLL
		#define LQD_API __declspec(dllexport)
	#else
		#define LQD_API __declspec(dllimport)
	#endif
#else
	#error Only support for Windows!
#endif
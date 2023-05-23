#pragma once

//
// For some reason preprocessor definition is not working 
// .... tried restting visual studio // reparing VS // Reinstalling VS but it wont fix
// So i am doing it in a diff way 
//

//#ifdef LQD_PLATFORM_WINDOWS
//	#ifdef LQD_BUILD_DLL
//		#define LIQUID_API __declspec(dllexport)
//	#else
//		#define LIQUID_API __declspec(dllimport)
//	#endif
//#else
//	#error Liquid only supports Windows!
//#endif 

// ------- TO BE REMOVED -------------------

#define LQD_PLATFORM_WINDOWS

#ifdef LQD_PLATFORM_WINDOWS
	#ifdef LQD_EXTRACT_DLL
	#define LIQUID_API __declspec(dllimport)
	#else
	#define LIQUID_API __declspec(dllexport)
	#endif
#else
	#error Liquid only supports Windows!
#endif 
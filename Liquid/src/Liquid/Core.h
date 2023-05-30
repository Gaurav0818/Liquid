#pragma once

// This macro defines the Liquid API macro.
// The Liquid API macro is used to mark functions and classes that are part of the Liquid Engine.
// This macro is different depending on whether the Liquid Engine is being built as a DLL or a static library.
// If the Liquid Engine is being built as a DLL, the Liquid API macro will be defined to `__declspec(dllexport)`.
// This tells the compiler that the function or class is exported from the DLL.
// If the Liquid Engine is being built as a static library, the Liquid API macro will be defined to `__declspec(dllimport)`.
// This tells the compiler that the function or class is imported from the DLL.
// The `LQD_PLATFORM_WINDOWS` macro is defined if the Liquid Engine is being built for Windows.
// The `LQD_BUILD_DLL` macro is defined if the Liquid Engine is being built as a DLL
#ifdef LQD_PLATFORM_WINDOWS
	#ifdef LQD_BUILD_DLL
		#define LIQUID_API __declspec(dllexport)
	#else
		#define LIQUID_API __declspec(dllimport)
	#endif
#else
	#error Liquid only supports Windows!
#endif 

// This macro defines the BIT macro.
// The BIT macro is used to get the bit mask for a given bit position.
// For example, BIT(0) will return 1, BIT(1) will return 2, and so on.
#define BIT(x) (1 << x)
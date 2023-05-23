#pragma once

#include "Core.h"

//#ifdef LQD_EXTRACT_DLL
//	#define LIQUID_API __declspec(dllimport)
//#else
//	#define LIQUID_API __declspec(dllexport)
//#endif


namespace LqD
{
	class LIQUID_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};

	// To Be Defined in Client 
	Application* CreateApplication();
}



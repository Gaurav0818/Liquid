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

		// This destructor is virtual so that it can be overridden in derived classes.
		// This is important for ensuring that all resources allocated by derived classes
		// are properly cleaned up when the application is shut down.
		virtual ~Application();

		void Run();

	};

	// This function is to be defined in the client code.
	// It creates an instance of the Application class.
	Application* CreateApplication();
}



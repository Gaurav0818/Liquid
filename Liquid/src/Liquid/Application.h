#pragma once

#include "Core.h"
#include "Window.h"

#include "Liquid/LayerStack.h"
#include "Events/Event.h"

namespace LqD
{
	class WindowCloseEvent;

	class LIQUID_API Application
	{
	public:
		Application();

		// This destructor is virtual so that it can be overridden in derived classes.
		// This is important for ensuring that all resources allocated by derived classes
		// are properly cleaned up when the application is shut down.
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// This function is to be defined in the client code.
	// It creates an instance of the Application class.
	Application* CreateApplication();
}



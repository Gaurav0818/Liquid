#include "pch.h"
#include "Application.h"

#include "Liquid/Events/ApplicationEvent.h"
#include "Liquid/Log.h"
#include <GLFW/glfw3.h>

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

LqD::Application::Application()
{
	m_Window = std::unique_ptr<Window>(Window::Create());
	m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
}

LqD::Application::~Application()
{
}

void LqD::Application::Run()
{
	while(m_Running)
	{
		// Clear the screen to a blue color.
		glClearColor(0.3,0.5,0.7,1);
		// Clear the color buffer.
		glClear(GL_COLOR_BUFFER_BIT);
		//We have to clear the color buffer because
		//it is used to store the colors of all the pixels on the screen.
		//When you start a new frame, you want to start with a blank canvas,
		//so you clear the color buffer to the background color.
		
		// Update the window.
		m_Window->OnUpdate();
	}
}

void LqD::Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
	
	LQD_CORE_INFO("{0}",e);
}

bool LqD::Application::OnWindowClose(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}



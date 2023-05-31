#include "pch.h"
#include "Application.h"

#include "Liquid/Events/ApplicationEvent.h"
#include "Liquid/Log.h"
#include <GLFW/glfw3.h>

LqD::Application::Application()
{
	m_Window = std::unique_ptr<Window>(Window::Create());
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



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
		glClearColor(0.3,0.5,0.7,1);
		glClear(GL_COLOR_BUFFER_BIT);
		m_Window->OnUpdate();
	}
}



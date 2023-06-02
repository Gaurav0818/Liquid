#include "pch.h"
#include "Application.h"

#include "Liquid/Events/ApplicationEvent.h"
#include "Liquid/Log.h"
#include "glad/glad.h"

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


		//UpdateEach Layer
		for(auto layer: m_LayerStack)
			layer->OnUpdate();
		
		// Update the window.
		m_Window->OnUpdate();
	}
}

void LqD::Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

	for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
	{
		(*--it)->OnEvent(e);
		if(e.Handled())
			break;
	}
}

void LqD::Application::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
}

void LqD::Application::PushOverlay(Layer* overlay)
{
	m_LayerStack.PushOverlay(overlay);
}

bool LqD::Application::OnWindowClose(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}



#include "pch.h"
#include "Application.h"

#include "Liquid/Events/ApplicationEvent.h"
#include "Liquid/Log.h"

LqD::Application::Application()
{
}

LqD::Application::~Application()
{
}

void LqD::Application::Run()
{
	WindowResizeEvent e(1280, 720);
	if (e.IsInCategory(EventCategoryApplication))
	{
		LQD_TRACE(e);
	}
	if (e.IsInCategory(EventCategoryInput))
	{
		LQD_TRACE(e);
	}

	while(true);
}



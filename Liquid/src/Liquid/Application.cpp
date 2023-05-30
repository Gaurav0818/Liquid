#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

LqD::Application::Application()
{
}

LqD::Application::~Application()
{
}

void LqD::Application::Run()
{
	WindowResizeEvent e(1280, 720);
	LQD_TRACE(e);

	while(true);
}



#pragma once
#include "App.h"

#ifdef LQD_PLATFORM_WINDOWS

extern lqd::Application* lqd::CreateApplication();

int main(int argc, char** argv)
{
	auto app = lqd::CreateApplication();
	app->Run();
	delete app;
}

#endif // LQD_PLATFORM_WINDOWS

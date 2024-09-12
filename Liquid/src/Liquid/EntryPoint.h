#pragma once

#ifdef LQD_PLATFORM_WINDOWS

extern lqd::Application* lqd::CreateApplication();

int main(int argc, char** argv)
{
	lqd::Log::Init();
	LQD_CORE_INFO("abcd");


	auto app = lqd::CreateApplication();
	app->Run();
	delete app;
}

#endif // LQD_PLATFORM_WINDOWS

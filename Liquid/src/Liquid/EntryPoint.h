#pragma once

//#ifdef LQD_PLATFORM_WINDOWS

extern LqD::Application* LqD::CreateApplication();

int main(int argc, char** argv)
{
	auto app = LqD::CreateApplication();
	app->Run();
	delete app;
}

//#endif 
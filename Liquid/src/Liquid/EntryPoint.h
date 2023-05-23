#pragma once


//By declaring the CreateApplication() function with the extern keyword, 
//we are telling the compiler that the function exists, 
//even though it is not defined in the current namespace. 
//This allows us to call the CreateApplication() function from the main() function.
extern LqD::Application* LqD::CreateApplication();

int main(int argc, char** argv)
{
	// This function is the main entry point for the application.
	// It creates an instance of the Application class, runs it, and then deletes it.

	LqD::Log::Init();
	LQD_CORE_WARN("Initialized Core Log!");
	LQD_INFO("Initialized Core Log!");
	LqD::Log::GetClientLogger()->info("Initialized Client Log!");


	// Create an instance of the Application class.
	auto app = LqD::CreateApplication();

	app->Run();
	
	delete app;
}

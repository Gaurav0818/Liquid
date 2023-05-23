#include "Liquid.h"


class Sandbox : public LqD::Application
{
public:
	Sandbox()
	{
		
	}

	~Sandbox()
	{
		
	}

};


// This function creates an instance of the Sandbox class.
LqD::Application* LqD::CreateApplication()
{
	// Return a pointer to a new Sandbox object.
	return new Sandbox();
}

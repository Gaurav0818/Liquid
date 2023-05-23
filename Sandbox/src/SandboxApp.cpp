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

LqD::Application* LqD::CreateApplication()
{
	return new Sandbox();
}

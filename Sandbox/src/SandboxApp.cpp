#include "pch.h"
#include "Liquid.h"

class ExampleLayer : public LqD::Layer
{
public :
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		LQD_INFO("ExampleLayer::Update");
	}

	void OnEvent(LqD::Event& event) override
	{
		LQD_TRACE("{0}", event);
	}
};

class Sandbox : public LqD::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
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
#include <Liquid.h>

class Project : public lqd::Application
{
public:
	Project()
	{

	}

	~Project()
	{

	}
};

lqd::Application* lqd::CreateApplication()
{
	return new Project();
}
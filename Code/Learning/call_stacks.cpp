#include <cstdio>
#include <stdexcept>

struct Object
{
	Object()
	{
		printf("Object Constructed\n");
	}

	~Object()
	{
		throw std::runtime_error{"Error Inside Destructor\n"};
	}
};

int main()
{
	try
	{
		Object obj1;
		throw std::runtime_error{"Error Inside Main\n"};
	}

	catch (const std::runtime_error& e)
	{
		printf(e.what());
	}
	return 0;
}
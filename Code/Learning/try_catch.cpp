#include <cstdio>
#include <stdexcept>

struct Age
{
	Age(int age)
	{
		if (age < 0)
			throw std::runtime_error{"Age cannot be negative, YOU FOOL!"};
	}

private:
	int age;
};

int main()
{
	try
    {
       Age obj1{-1};
       Age obj2{0};
       Age obj3{17}; 
    }

    catch(const std::runtime_error& e)
    {
        printf("Exception caught with message: %s\n", e.what());
    }
    return 0;
}
#include <cstdio>
#include <stdexcept>

struct Age
{
	Age(int age)
	{
		if (age < 0)
			throw std::runtime_error{"Age cannot be negative, YOU FOOL!"};
		age=age;
	}

	void getAge()
	{
		printf("%d", age);
	}
private:
	int age;
};

int main()
{
	Age myAge{-1};
	return 0;
}
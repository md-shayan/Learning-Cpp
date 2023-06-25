#include <cstdio>

struct Life
{
	Life(const char* name) : name{name}
	{
		printf("%s constructed.\n", name);
	}

	~Life()
	{
		printf("%s destructed.\n", name);
	}

private:
	const char* name;
};

static Life obj1{"static Object"};
thread_local Life obj2{"thread_local Object"};

int main()
{
	printf("A\n");
	Life obj3{"main Object"};
	printf("B\n");
	const Life* obj4 = new Life{"pointer Object"};
	printf("C\n");
	return 0;
}
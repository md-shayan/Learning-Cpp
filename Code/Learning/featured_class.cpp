#include <cstdio>

struct Details
{
	Details()
	{
		printf("No Details Given\n");
	}

	Details(int id)
	{
		printf("Consists Id\n");
	}

	Details(char name[])
	{
		printf("Consists Name\n");
	}
};

int main()
{
	char name[]{"Shayan"};
	Details emp1;
	Details emp2(03);
	Details emp3(name);
}
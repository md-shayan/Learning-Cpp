#include <cstdio>

struct Date
{
	Date()
	{
		printf("16-06-2023\n");
	}

	~Date()
	{
		printf("Date Has Been Destroyed\n");
	}
};

int main()
{
	Date today;
}
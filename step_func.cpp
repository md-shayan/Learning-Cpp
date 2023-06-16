#include <cstdio>

int step_function(int x)
{
	int result = 0;

	if (x < 0)
	{
		result = -1;
	}
	else if (x > 0)
	{
		result = 1;
	}

	return result;
}

int main()
{
	int value1 = 10;
	int step1 = step_function(value1);
	
	int value2 = 0;
	int step2 = step_function(value2);
	
	int value3 = -10;
	int step3 = step_function(value3);

	printf("Number:%d, Step:%d\n", value1, step1);
	printf("Number:%d, Step:%d\n", value2, step2);
	printf("Number:%d, Step:%d\n", value3, step3);

	return 0;
}
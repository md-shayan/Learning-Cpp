#include <cstdio>

int sum(int a, int b)
{
	return a+b;
}

int main()
{
	int x = 10;
	int y = 12;
	int add = sum(x, y);

	printf("The Sum Of %d and %d Is %d", x, y, add);
}
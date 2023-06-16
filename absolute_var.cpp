#include <cstdio>

int absolute_int(int x)
{
	if (x >= 0) return x;
	else return -1*x;
}

int main()
{
	int x = -12;
	int x_absolute = absolute_int(x);

	printf("x:%d, |x|:%d", x, x_absolute);
	return 0;
}
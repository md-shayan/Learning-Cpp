#include <cstdio>
#include <stdexcept>

bool isEven(int x) noexcept
{
	return (!x%2==0);
}

int main()
{
	bool x = isEven(2);
	printf("%d", x);
	return 0;
}
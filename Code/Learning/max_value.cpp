#include <cstdio>

int main()
{
	int arr[] = {10, 20, 30, 40, 50};
	int max_value = 0;
	for (int elem : arr)
	{
		if (elem > max_value)
		{
			max_value = elem;
		}
	}

	printf("%d", max_value);
}
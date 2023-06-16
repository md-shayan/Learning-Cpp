#include <cstdio>

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	for (int elem : arr)
	{
		if ((elem % 2) != 0)
		{
			printf("%d", elem);
		}
	}
}
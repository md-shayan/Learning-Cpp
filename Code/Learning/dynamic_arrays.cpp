#include <cstdio>

int main()
{
	int* arr = new int[5];
	printf("%d", arr);
	delete[] arr; // Deallocating arr[].
	return 0;
}
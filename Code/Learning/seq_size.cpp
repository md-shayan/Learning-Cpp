#include <cstdio>
#include <cstddef>

int main()
{
	int arr[] = {10, 20, 30, 40, 50, 60};
	size_t size_of_arr = sizeof(arr) / sizeof(int);
	/*
	 * sizeof(arr) returns the size of the data type of each element in bytes (4 since the elements are int) times no. of element (6) -> 4*6 = 24
	 * sizeof(int) returns the size of the data type int which is 4 bytes.
	 * Upon division sizeof(int) cancels out and what is left is the no. of elements.
	*/
	printf("%zd", size_of_arr);
}
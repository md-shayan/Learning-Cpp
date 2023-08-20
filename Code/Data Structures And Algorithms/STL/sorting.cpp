// std::sort(start_address, end_address)
// std::sort(std::begin(A), std::end(A))
// std::sort(&A[0], &A[N])
// std::sort(&A[0], &A[0]+N)

// To sort in reverse order use std::greater()
// std::sort(start_address, end_address, std::greater<T>()), where T is the type of data in array

// Time Complexity: O(NlogN)
// Space Complexity: O(1)

#include <iostream>
#include <algorithm>

void printArray(int* arr, int size) {
	std::cout << "{";
	for (int i=0; i<size; i++) {
		std::cout << " " << arr[i];
	}
	std::cout << " }" << std::endl;
}

int main() {
	int arr[]{5, 4, 3, 2, 1};
	int* ptr = arr;
	int size = sizeof(arr) / sizeof(int);
	printArray(arr, size);

	// Sort in ascending order
	std::sort(std::begin(arr), std::end(arr));
	printArray(arr, size);

	// Sort in descending order
	std::sort(std::begin(arr), std::end(arr), std::greater<int>());
	printArray(arr, size);
	return 0;
}

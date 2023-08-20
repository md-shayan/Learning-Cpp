// std::binary_search(start_address, end_address, elemToFind) -> returns bool

// Time Complexity: O(logN)
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
	int size = sizeof(arr) / sizeof(int);
	printArray(arr, size);
	std::sort(std::begin(arr), std::end(arr));
	printArray(arr, size);
	std::cout << std::binary_search(std::begin(arr), std::end(arr), 3) << std::endl;
	std::cout << std::binary_search(std::begin(arr), std::end(arr), 0) << std::endl;   
	return 0;
}

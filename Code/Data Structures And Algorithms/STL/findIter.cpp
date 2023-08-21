// std::find(start_address, end_address, elemToFind)
// Returns a pointer to the first occuring element in given address which equals elemToFind
// If none is found, then it returns a pointer to the end address as given.

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
	int arr[]{1, 2, 3, 2, 4, 5};
	int size = sizeof(arr) / sizeof(int);
	printArray(arr, size);
	std::cout << std::find(std::begin(arr), std::end(arr), 2) << std::endl;
	std::cout << std::find(std::begin(arr), std::end(arr), 6) << std::endl;
	return 0;
}

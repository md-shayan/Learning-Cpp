// std::count(start_address, end_address, elemToCount)

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
	int arr[]{1, 2, 3, 4, 2, 5};
	int size = sizeof(arr) / sizeof(int);
	printArray(arr, size);
	std::cout << std::count(std::begin(arr), std::end(arr), 2) << std::endl;
	return 0;
}

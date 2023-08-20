// std::reverse(start_address, end_address)

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
	std::reverse(std::begin(arr), std::end(arr));
	printArray(arr, size);
	return 0;
}

// std::max(start_address, end_address) -> address of the max element
// std::min(start_address, end_address) -> address of the min element 

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
	int arr[]{1, 2, 3, 4, 5};
	int size = sizeof(arr) / sizeof(int);
	printArray(arr, size);
	std::cout << *std::max_element(std::begin(arr), std::end(arr)) << std::endl;
	std::cout << *std::min_element(std::begin(arr), std::end(arr)) << std::endl;
	return 0;
}

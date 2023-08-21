// std::lower_bound(start_address, end_address, value)
// returns a pointer pointing to the first element in the range [start_address, end_address) which
// has a value not less than 'value'.

// std::upper_bound(start_address, end_address, value)
// returns a pointer pointing to the first element in the range [start_address, end_address) which
// has a value greater than 'value'.

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
	int arr[]{5, 10, 15, 20, 20, 23, 42, 45};
	int size = sizeof(arr) / sizeof(int);
	printArray(arr, size);
	std::cout << std::lower_bound(std::begin(arr), std::end(arr), 20) << std::endl;
	std::cout << std::upper_bound(std::begin(arr), std::end(arr), 20) << std::endl;
	return 0;
}

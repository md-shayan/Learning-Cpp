// std::partition_copy(start_address, end_address, start_address_TRUE, start_address_FALSE, [](T x){return <condition>;})
// Goes over the elements in the given address range
// If condition is satisfied, copies the element in start_address_TRUE and increments it
// Otherwise, copies the element in start_address_FALSE and increments it

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
	int arr[]{1, -1, 2, -2, 3, -3, 4, -4, 5, -5};
	int size = sizeof(arr) / sizeof(int);
	printArray(arr, size);
	int positive_arr[5] = {0};
	int negative_arr[5] = {0};
	std::partition_copy(std::begin(arr), std::end(arr), std::begin(positive_arr), std::begin(negative_arr), [](int x) {return x>=0;});
	printArray(positive_arr, 5);
	printArray(negative_arr, 5);
	return 0;
}

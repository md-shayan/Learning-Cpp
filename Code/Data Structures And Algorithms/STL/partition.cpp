// std::partition(start_address, end_address, [](T x) {return <condition>;})
// Shifts all the elements that satisfies the given conditon in address range to the left of the range

// std::stable_partition(start_address, end_address, [](T x) {return <conditon>;})
// Shifits all the elements that satisfies the given condition in address range to the left of the address // range while also maintaining the order of the appearance of the elements

// std::partition_point(start_address, end_address, [](T x) {return <condition>;})
// Returns the address of the first element where the given condition is not satisfied

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
	
	std::stable_partition(std::begin(arr), std::end(arr), [](int x) {return x<0;});
	printArray(arr, size);

	std::cout << "Partition Point: " << std::partition_point(std::begin(arr), std::end(arr), [](int x) {return x<0;}) - std::begin(arr) << std::endl;

	std::partition(std::begin(arr), std::end(arr), [](int x) {return x%2==0;});
	printArray(arr, size);
	return 0;
}

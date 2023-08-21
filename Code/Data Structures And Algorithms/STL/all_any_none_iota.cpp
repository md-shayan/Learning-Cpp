// std::all_of(start_address, end_address, [](T x) {return <condition>;})
// Returns true if all the elements in the given address range satisfies the given condition.

// std::any_of(start_address, end_address, [](T x) {return <condition>;})
// Returns true if any of the element in the given address range satisfies the given condition.

// std::none_of(start_address, end_address, [](T x) {return <condition>;})
// Returns true if none of the element in the given address range satisfies the given condition.

// std::copy_n(from_arr, elems, to_arr)
// Copies 'elems' number of elements from from_arr into to_arr.

// std::iota(start_address, end_address, start_value)
// Fills the given address range with consecutive values starting from the given 'start_value'.

#include <iostream>
#include <algorithm>
#include <numeric>

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

	std::all_of(std::begin(arr), std::end(arr), [](int x)  {return x<6;}) ? std::cout << "All are less than 6" << std::endl : std::cout << "Not all are less than 6" << std::endl;


	std::any_of(std::begin(arr), std::end(arr), [](int x) {return x<0;}) ? std::cout << "At least one element is less than zero" << std::endl : std::cout << "No element is less than zero" << std::endl;

	std::none_of(std::begin(arr), std::end(arr), [](int x) {return x<6;}) ? std::cout << "At least one is greater than 6" << std::endl : std::cout << "All are less than 6" << std::endl;	

	int new_arr[size];
	std::copy_n(arr, size, new_arr);
	printArray(new_arr, size);

	new_arr[0] = {0};
	std::iota(new_arr, new_arr+6, 1);
	printArray(new_arr, size);

	return 0;
}

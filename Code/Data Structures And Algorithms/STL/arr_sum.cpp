// std::accumulate(start_address, end_address, start_value)

#include <iostream>
#include <numeric>

void printArray(char* arr, int size) {
	std::cout << "{";
	for (int i=0; i<size; i++) {
		std::cout << " " << arr[i];
	}
	std::cout << " }" << std::endl;
}

int main() {
	char arr[]{'a', 'b', 'c', 'd', 'e'};
	int size = sizeof(arr);
	printArray(arr, size);
	std::cout << std::accumulate(std::begin(arr), std::end(arr), 0) << std::endl;
	return 0;
}

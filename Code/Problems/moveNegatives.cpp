/*
 * Move all the negative integers to one side of the array (order is irrelevant).
 * Time Complexity: O(N)
 * Space Complexity: O(1)
*/

#include <iostream>

void moveNegatives(int arr[], int size) {
	int i = 0;
	int neg = 0;
	while (i < size) {
		if (arr[i] < 0) {
			int temp = arr[neg];
			arr[neg] = arr[i];
			arr[i] = temp;
			neg++;
		}
		i++;
	}
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout<<arr[i]<<", ";
	}
	std::cout<<std::endl;
}

int main() {
	int arr[]{-12, 11, -13, -5, 6, -7, 5, -3, -6};
	int size = sizeof(arr) / sizeof(int);
	moveNegatives(arr, size);
	printArray(arr, size);
	return 0;
}
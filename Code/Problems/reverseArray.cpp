/*
 * Write a program to reverse the array.
 * Time Complexity: O(N)
 * Space Complexity: O(1)
*/

#include <iostream>

void reverseArray(int arr[], int from, int to) {
	to--;
	while (from < to-1) {
		int temp = arr[from];
		arr[from] = arr[to];
		arr[to] = temp;
		from++;
		to--;
 	}
}

void printArray(int arr[], int size) {
	for (int i=0; i<size; i++) {
		std::cout<<arr[i];
	}
	std::cout<<std::endl;
}

int main() {
	int arr[]{1, 2, 3, 4, 5};
	std::cout<<"Original Array:";
	printArray(arr, 5);
	reverseArray(arr, 0, 5);
	std::cout<<"Reversed Array:";
	printArray(arr, 5);
	return 0;
}
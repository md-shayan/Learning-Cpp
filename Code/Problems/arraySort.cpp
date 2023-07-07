/*
 * Write a program end sort the given array.
 * Time Complexity: O(N^2)
 * Space Complexity: O(1)
*/

#include <iostream>

// Returns the index of the largest element in arr[].
int max(int arr[], int size) {
	int i=0;
	int max = 0;
	int maxIndex = 0;
	while (i < size) {
		if (arr[i] > max) {
			max = arr[i];
			maxIndex = i;
		}
		i++;
	}
	return maxIndex;
}


void arraySort(int arr[], int size) {
	int i=0;
	while (i < size) {
		int maxIndex = max(arr, size-i);
		int temp = arr[size-i-1];
		arr[size-i-1] = arr[maxIndex];
		arr[maxIndex] = temp;
		i++;
	}
}

void printArray(int arr[], int size) {
	int i=0;
	std::cout<<"{";
	while (i<size) {
		std::cout<<arr[i]<<", ";
		i++;
	}
	std::cout<<"}"<<std::endl;
}

int main() {
	int arr[]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int n = sizeof(arr) / sizeof(int);
	printArray(arr, n);
	arraySort(arr, n);
	printArray(arr, n);
}
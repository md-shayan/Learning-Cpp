// Given an array of elements of length N, ranging from 0 to N – 1.
// Rearrange the array such that A[i] = i and if i is not present, display -1 at that place.

#include <iostream>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void rearrangeArray(int A[], int N) {
	int correct = -1;
	int i = 0;
	while (i < N) {
		correct = A[i];
		if (A[i] != -1 && A[i] != A[correct]) {swap(A[i], A[correct]);}
		else {i++;}
	}
}

int main() {
	int arr[]{-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
	int size = sizeof(arr) / sizeof(int);
	rearrangeArray(arr, size);
	for (int i=0; i<size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}

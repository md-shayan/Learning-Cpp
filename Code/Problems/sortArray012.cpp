/*
 * Sort the array of 0s, 1s, and 2s.
 * Time Complexity: O(N)
 * Space Complexity: O(1)
*/

#include <iostream>

int sortArray(int arr[], int size) {
	int zeros = 0;
	int ones = 0;
	int twos = 0;
	for (int i=0; i<size; i++) {
		switch (arr[i]) {
		case 0:
			zeros++;
			break;
		case 1:
			ones++;
			break;
		case 2:
			twos++;
			break;
		}
	}

	int i=0;
	while (zeros) {
		arr[i++] = 0;
		zeros--;
	}

	while (ones) {
		arr[i++] = 1;
		ones--;
	}

	while (twos) {
		arr[i++] = 2;
		twos--;
	}
}

int main() {
	int arr[]{0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
	int size = sizeof(arr) / sizeof(int);
	sortArray(arr, size);
	for (int i=0; i<size; i++) std::cout<<arr[i];
}
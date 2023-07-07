/*
 * Find the occurrence of an integer in the array.
 * Time Complexity: O(N)
 * Space Complexity: O(1)
*/

#include <iostream>

int findOccurence(int arr[], int K, int size) {
	int occurenceK = 0;
	int i=0;
	while (i < size) {
		if (arr[i] == K) occurenceK++;
		i++;
	}
	return occurenceK;
}

int main() {
	int arr[]{5, 3, 2, 2, 2, 2, 4, 1};
	int size = sizeof(arr) / sizeof(int);
	int x = findOccurence(arr, 2, size);
	std::cout<<x;
}
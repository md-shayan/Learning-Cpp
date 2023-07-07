/*
 * Find the Kth largest and Kth smallest number in an array.
 * Time Compelxity: O(N)
 * Space Complexity: O(1)
*/

#include <iostream>

struct Points {
	int Klargest;
	int Ksmallest;
};

int maxIndex(int arr[], int size) {
	int i = 0;
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

Points KthLargestSmallest(int arr[], int k, int size) {
	int i = 0;
	while(i < size) {
		int max = maxIndex(arr, size-i);
		int temp = arr[size-i-1];
		arr[size-i-1] = arr[max];
		arr[max] = temp;
		i++;
	}
	Points p;
	p.Klargest = arr[size-k];
	p.Ksmallest = arr[k-1];
	return p;
}

int main() {
	int arr[]{5, 3, 2, 4, 7};
	int n = sizeof(arr) / sizeof(int);
	int K = 1;
	Points s = KthLargestSmallest(arr, 1, n);
	std::cout<<s.Klargest<<std::endl;
	std::cout<<s.Ksmallest<<std::endl;
	return 0;
}
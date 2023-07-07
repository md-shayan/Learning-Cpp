/*
 * Given two sorted arrays, find their union and intersection.
 * Time Complexity: O(M + N) (for both operations)
 * Space Complexity: O(1) (for both operations)
*/
#include <iostream>

void findUnion(int arr1[], int size1, int arr2[], int size2) {
	int i=0;
	int j=0;
	std::cout<<"{";
	while (i<size1 && j<size2) {
		if (arr1[i] < arr2[j]) {
			std::cout<<arr1[i]<<", ";
			i++;
		}

		if (arr1[i] > arr2[j]) {
			std::cout<<arr2[j]<<", ";
			j++;
		}

		if (arr1[i] == arr2[j]) {
			std::cout<<arr1[i]<<", ";
			i++;
			j++;
		}
	}

	if (size1 > size2) {
		for (i; i<size1; i++) std::cout<<arr1[i]<<", ";
	}

	else {
		for (j; j<size2; j++) std::cout<<arr2[j]<<", ";
	}
	std::cout<<"}";
}

void findIntersection(int arr1[], int size1, int arr2[], int size2) {
	int i=0;
	int j=0;
	std::cout<<"{";
	while (i<size1 && j<size2) {
		if (arr1[i] < arr2[j]) i++;
		if (arr1[i] > arr2[j]) j++;
		if (arr1[i] == arr2[j]) {
			std::cout<<arr1[i]<<", ";
			i++;
			j++;
		}
	}
	std::cout<<"}";
}

int main() {
	int arr1[]{1, 3, 4, 5, 7};
	int arr2[]{2, 3, 5, 6};
	int m = sizeof(arr1) / sizeof(int);
	int n = sizeof(arr2) / sizeof(int);
	std::cout<<"Union:";
	findUnion(arr1, m, arr2, n);
	std::cout<<std::endl;
	std::cout<<"Intersection:";
	findIntersection(arr1, m, arr2, n);
}
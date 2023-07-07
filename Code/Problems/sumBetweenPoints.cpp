/*
 * Given an array, find a subarray inside array such that the sum of array is equal to the given sum.
 * Return the indices of the subarray inside array
 * Time Complexity: O(N^2)
 * Space Complexity: O(1)
*/

#include <iostream>

struct Points {
	int pointA;
	int pointB;
};

Points arraySum(int arr[], int sum, int size) {
	Points sumPoints;
	sumPoints.pointA = -1;
	sumPoints.pointB = -1;
	for (int i = 0; i < size; i++) {
		int sumSoFar = arr[i];
		int j = i+1;
		while (j < size) {
			if (sumSoFar == sum) {
				sumPoints.pointA = i;
				sumPoints.pointB = j-1;
				return sumPoints;
			}
			sumSoFar += arr[j];
			j++;
		}
	}
	std::cout<<"No subarray with sum found"<<std::endl;
	return sumPoints;
}

int main() {
	int arr[]{1, 4, 0, 0, 3, 10, 5};
	int size = sizeof(arr) / sizeof(int);
	Points solution = arraySum(arr, 150, size);
	std::cout<<"Sum found between arr["<<solution.pointA<<"] and arr["<<solution.pointB<<"]"<<std::endl;
	return 0;
}
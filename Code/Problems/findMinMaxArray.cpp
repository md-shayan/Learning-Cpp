/*
 * Find the minimum and maximum element in an array.
 * Time Complexity: O(N)
 * Space Complexity: O(1)
*/

#include <iostream>

struct Pair {
	int max;
	int min;
};

Pair findMinMax(int arr[], int from, int to) {
	Pair minMax;
	minMax.max = arr[from];
	minMax.min = arr[from];

	while (from < to) {
		if (arr[from] > minMax.max) minMax.max = arr[from];
		if (arr[from] < minMax.min) minMax.min = arr[from];
		from++;
	}
	return minMax;
}

int main() {
	int arr[]{1, 2, 3, 4, 5};
	Pair solutions = findMinMax(arr, 0, 5);
	
	std::cout<<"Minimum:"<<solutions.min<<std::endl;
	std::cout<<"Maximum:"<<solutions.max<<std::endl;
	return 0;
}
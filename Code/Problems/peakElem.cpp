/*
 * Find All Peak Elements Which Are Not Smaller Than It's Neighbouring Elements.
 * Time Complexity: O(N)
 * Space Compleity: O(1)
*/

#include <iostream>

void peakElems(int arr[], int from, int to) {
	to--;
	while (from < to) {
		if (from == 0 && arr[from] > arr[from+1]) std::cout<<arr[from]<<std::endl;
		if (from == to && arr[from] > arr[from-1]) std::cout<<arr[from]<<std::endl;
		if (arr[from] > arr[from+1] && arr[from] > arr[from-1]) std::cout<<arr[from]<<std::endl;
		from++;
	}
}

int main() {
	int arr[]{10, 20, 15, 2, 23, 90, 67};
	peakElems(arr, 0, 7);
}
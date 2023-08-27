// INSERTION_SORT(A):
// while i=0 upto N-1:
// 	key = A[i]
// 	j = i-1
// 	while j >=0 and A[j] >= key:
// 		A[j+1] = A[j]
// 		j = j-1
// 	A[j+1] = key
// 	i++

// Time Complexity: O(N^2)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void insertion_sort(std::vector<int>& A) {
	int i=0;
	int key, j;
	while (i < A.size()) {
		key = A[i];
		j = i-1;
		while (j >= 0 && A[j] >= key) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
		i++;
	}
}

void printArray(std::vector<int> A) {
	std::cout << "{";
	for (int i=0; i<A.size(); i++) {
		std::cout<< " " << A[i];
	}
	std::cout << " }" << std::endl;
}

int main() {
	std::vector<int> A;
	A.resize(20);
	std::iota(A.begin(), A.end(), 1);
	std::reverse(A.begin(), A.end());
	printArray(A);
	insertion_sort(A);
	printArray(A);
	insertion_sort(A);
	printArray(A);
	return 0;
}

// RECURSIVE_INSERTION_SORT(A, N):
// if N == 1
// 	return
// RECURSIVE_INSERTION_SORT(A, N-1)
// last = A[N-1]
// j = N-2
// while j>=0 and A[j] > last
// 	A[j+1] = A[j]
// 	j--
// A[j+1] = last

// Time Complexity: O(N^2)
// Space Complexity: O(N)

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void recursive_insertion_sort(std::vector<int>& A, int size) {
	if (size == 1) {return;}
	recursive_insertion_sort(A, size-1);
	int last = A[size-1];
	int j = size-2;
	while (j >= 0 && A[j] > last) {
		A[j+1] = A[j];
		j--;
	}
	A[j+1] = last;
}

void printArray(std::vector<int> A) {
	std::cout << "{";
	for (int i=0; i<A.size(); i++) {
		std::cout << " " << A[i];
	}
	std::cout << " }" << std::endl;
}

int main() {
	std::vector<int> A;
	A.resize(20);
	std::iota(A.begin(), A.end(), 1);
	std::reverse(A.begin(), A.end());
	printArray(A);
	recursive_insertion_sort(A, A.size());
	printArray(A);
	return 0;
}

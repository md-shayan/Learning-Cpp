// FIND_SMALLEST_AFTER_K(A, K):
// smallest = K
// i = K+1
// while i < A.size
// 	if A[i] < smallest
// 		smallest = i
// 	i++

// INSERTION_SORT(A):
// for i=0 to N-1:
// 	smallest = FIND_SMALLEST_AFTER_K(A, i)
// 	swap A[smallest] and A[i]

// Time Complexity: O(N^2) [find_smallest_after_k, O(N), is called N times]
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int find_smallest_after_K(std::vector<int> A, int k) {
	int smallest = k;
	int i = k+1;
	while (i < A.size()) {
		if (A[i] < A[smallest]) {smallest = i;}
		i++;
	}
	return smallest;
}

void insertion_sort(std::vector<int>& A) {
	for (int i=0; i<A.size(); i++) {
		int smallest = find_smallest_after_K(A, i);
		swap(A[smallest], A[i]);
	}
}

void printArray(std::vector<int> A) {
	std::cout << "{";
	for (auto i=A.begin(); i!=A.end(); i++) {
		std::cout << " " << *i;
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
	return 0;
}

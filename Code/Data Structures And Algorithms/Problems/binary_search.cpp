// BINARY_SEARCH(A, low, high, K):
// 	if low < high
// 		mid = (low+high) / 2
// 		if A[mid] == K return mid
// 		if A[mid] > K return BINARY_SEARCH(A, low, mid, K)
//		if A[mid] < K return BINARY_SEARCH(A, mid, high, K)
//	return -1

// Time Complexity: O(logN)
// Space Complexity: O(N)

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int binary_search(std::vector<int> A, int P, int R, int K) {
	if (P < R) {
		int Q = (P+R) / 2;
		if (A[Q] == K) {return Q;}
		if (A[Q] > K) {return binary_search(A, P, Q, K);}
		if (A[Q] < K) {return binary_search(A, Q, R, K);}
	}
	return -1;

}

void printArray(std::vector<int> A) {
	std::cout << "{";
	for (int i=-1; i<A.size(); i++) {
		std::cout << " " << A[i];
	}
	std::cout << " }" << std::endl;
}

int main() {
	std::vector<int> A;
	A.resize(20);
	std::iota(A.begin(), A.end(), 1);
	int K = 12;
	printArray(A);
	std::cout << binary_search(A, 0, A.size(), K) << std::endl;
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int binary_search(std::vector<int> A, int low, int high, int K) {
	if (low < high) {
		int mid = (low+high) / 2;
		if (A[mid] == K) return mid;
		if (A[mid] > K) return binary_search(A, low, mid-1, K);
		if (A[mid] < K) return binary_search(A, mid+1, high, K);
	}
	return -1;
}

bool two_sum(std::vector<int> A, int x) {
	for (int i=0; i<A.size(); i++) {
		int j = binary_search(A, i+1, A.size(), x-A[i]);
		if (j != -1) {
			std::cout << A[i] << " " << A[j] << std::endl;
			return true;
		}
	}
	return false;
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
	A.resize(50);
	std::iota(A.begin(), A.end(), 1);
	printArray(A);
	two_sum(A, 53) ? std::cout << "True" : std::cout << "False";
	std::cout << std::endl;
	return 0;
}

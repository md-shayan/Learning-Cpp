// MERGE(A, P, Q, R):
// nL = Q-P+1
// nR = R-Q
// Let L be an array of size nL
// Let R be an array of size nR
// for i=0 upto nL
// 	L[i] = A[P+i]
// for j=0 upto nR
// 	R[i] = A[Q+j+1]
// i = 0
// j = 0
// k = p
// while i < nL && j < nR
// 	if L[i] <= R[j]
// 		A[k] = L[i]
// 		k++
// 		i++
// 	else
// 		A[k] = R[j]
// 		k++
// 		j++
// while i < nL
// 	A[k] = L[i]
// 	k++
// 	i++
// while j < nR
// 	A[k] = R[j]
// 	k++
// 	j++

// MERGE_SORT(A, P, R):
// if P >= R
// 	return
// Q = (P+R) / 2
// MERGE_SORT(A, P, Q)
// MERGE_SORT(A, Q+1, R)
// MERGE(A, P, Q, R)

// Time Complexity: O(Nlog𝟸N)
// Space Complexity: O(N)

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void merge(std::vector<int>& A, int p, int q, int r) {
	int left_size, right_size;
	left_size = q-p+1;
	right_size = r-q;
	std::vector<int> L;
	std::vector<int> R;
	L.resize(left_size);
	R.resize(right_size);
	for (int i=0; i<left_size; i++) {L[i] = A[p+i];}
	for (int j=0; j<right_size; j++) {R[j] = A[q+j+1];}
	int i=0;
	int j=0;
	int k=p;
	while (i < left_size && j < right_size) {
		if (L[i] <= R[j]) {A[k] = L[i++];}
		else {A[k] = R[j++];}
		k++;
	}
	while (i < left_size) {A[k++] = L[i++];}
	while (j < right_size) {A[k++] = R[j++];}
}

void merge_sort(std::vector<int>& A, int p, int r) {
	if (p >= r) {return;}
	int q = (p+r) / 2;
	merge_sort(A, p, q);
	merge_sort(A, q+1, r);
	merge(A, p, q, r);
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
	merge_sort(A, 0, A.size()-1);
	printArray(A);
	return 0;
}

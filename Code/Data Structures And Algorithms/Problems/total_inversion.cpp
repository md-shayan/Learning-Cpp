#include <iostream>
#include <vector>

int inversions = 0;

// Time Complexity: O(N logN)
// Space Complexity: O(N)
void count_inversions(std::vector<int>& A, int p, int q, int r) {
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
		else {
			// Since L and R are sorted array, if L[i] > R[j]
			// then all the elements to the right of L[i] are also inversions.
			inversions += left_size - i;
			A[k] = R[j++];
		}
		k++;
	}
	while (i < left_size) {A[k++] = L[i++];}
	while (j < right_size) {A[k++] = R[j++];}
}

void total_inversions(std::vector<int>& A, int p, int r) {
	if (p >= r) {return;}
	int q = (p+r) / 2;
	total_inversions(A, p, q);
	total_inversions(A, q+1, r);
	count_inversions(A, p, q, r);
}

void printArray(std::vector<int> A) {
        std::cout << "{";
        for (int i=0; i<A.size(); i++) {std::cout << " " << A[i];}
        std::cout << " }" << std::endl;
}

int main() {
	std::vector<int> A = {2, 3, 8, 6, 1, 2, 0};
	A.resize(7);
	printArray(A);
	total_inversions(A, 0, A.size()-1);
	std::cout << inversions << std::endl;
	return 0;
}

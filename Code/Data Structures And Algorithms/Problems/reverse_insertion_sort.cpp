#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

void reverse_insertion_sort(std::vector<int>& A) {
        int i=0;
        int key, j;
        while (i < A.size()) {
                key = A[i];
                j = i-1;
                while (j >= 0 && key >= A[j]) {
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
        printArray(A);
        reverse_insertion_sort(A);
        printArray(A);
        return 0;
}


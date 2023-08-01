#include <iostream>
#include "array.h"

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//Time Complexity: O(N^2)
//Space Complexity: O(1)
void bubbleSort(int A[], int size) {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size-1; j++) {
            if (A[j] > A[j+1]) {
                swap(A[j], A[j+1]);
            }
        }
    }
}

int main() {
    int arr[]{5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    A.print();
    bubbleSort(A.getArray(), A.getSize());
    A.print();
    return 0;

}
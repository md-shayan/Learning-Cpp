#include <iostream>
#include "array.h"

void selectionSort(int A[], int start, int end) {
    if (start < end) {
        int min = start;
        for (int i=start; i<end; i++) {
            if (A[i] < A[min]) {
                min = i;
            }
        }
        int temp = A[start];
        A[start] = A[min];
        A[min] = temp;
        selectionSort(A, start+1, end);
    }
}


int main() {
    int arr[]{5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    A.print();
    selectionSort(A.getArray(), 0,  A.getSize());
    A.print();
    return 0;
}
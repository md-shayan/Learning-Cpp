//Given an array arr[] of size N, the task is to rotate the array by d position to the left.
#include <iostream>
#include "array.h"

//Time Complexity: O(N)
//Space Complexity: O(N)
void shiftArray(int A[], int size, int K) {
    int* temp = new int[size];
    int k=0;
    for (int i=K; i<size; i++) {
        temp[k++] = A[i];
    }
    for (int j=0; j<K; j++) {
        temp[k++] = A[j];
    }
    for (k=0; k<size; k++) {
        A[k] = temp[k];
    }
}

int main() {
    int arr[]{1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    A.print();
    shiftArray(A.getArray(), A.getSize(), 2);
    A.print();
    return 0;
}
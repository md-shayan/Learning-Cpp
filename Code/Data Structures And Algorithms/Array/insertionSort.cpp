#include <iostream>
#include "array.h"

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int A[], int size) {
    for (int i=1; i<size; i++) {
        int key = A[i];
        int j=i-1;
        while (j >= 0 && A[j] > key) {
            if (A[j] > key) {
                swap(A[j], A[j+1]);
            }
            j--;
        }
    }
}

int main() {
    int arr[]{5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    A.print();
    insertionSort(A.getArray(), A.getSize());
    A.print();
    return 0;
}
//Given an array of size n and multiple values around which we need to left rotate the array.
//How to quickly print multiple left rotations?
#include <iostream>
#include "array.h"

//Time Complexity: O(N)
//Space Complexity: O(1)
void printArray(int A[], int from, int to) {
    for (int i=from; i<to; i++) {
        std::cout<<A[i]<<" ";
    }
}

//Time Complexity: O(N)
//Space Complexity: O(1)
void multipleRotations(int A[], int size, int K) {
    if (K%size != 0) {
        printArray(A, K%size, size);
        printArray(A, 0, K%size);
        std::cout<<std::endl;
    }
    else {
        printArray(A, 0, size);
        std::cout<<std::endl;
    }
}

int main() {
    int arr[]{1, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    multipleRotations(A.getArray(), A.getSize(), 1);
    multipleRotations(A.getArray(), A.getSize(), 4);
    multipleRotations(A.getArray(), A.getSize(), 6);
    multipleRotations(A.getArray(), A.getSize(), 8);
    multipleRotations(A.getArray(), A.getSize(), 14);
    return 0;
}
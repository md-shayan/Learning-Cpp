//Given an array of integers, our task is to write a program that efficiently
//finds the second-largest element present in the array. 
#include <iostream>
#include "array.h"

//Time Complexity: O(N)
//Space Complexity: O(1)
int secondLargest(int A[], int size) {
    int largest = INT32_MIN;
    int result = INT32_MIN;
    for (int i=0; i<size; i++) {
        if (A[i] > largest) {
            largest = A[i];
        }
        if (A[i] > result && A[i] < largest) {
            result = A[i];
        }
    }
    return result;
}

int main() {
    int arr[]{10, 5, 10};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    std::cout<<secondLargest(A.getArray(), A.getSize());
    return 0;
}
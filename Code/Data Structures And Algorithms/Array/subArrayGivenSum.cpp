//Given an array A of non-negative integers and an integer sum, find a subarray that adds to a given sum.

#include <iostream>
#include "array.h"

//Time Complexity: O(N^2)
//Space Complexity: O(1)
void FindGivenSum(int A[], int size, int sum) {
    int sumSoFar;
    for (int i=0; i<size; i++) {
        sumSoFar = 0;
        for (int j=i; j<size; j++) {
            sumSoFar += A[j];
            if (sumSoFar == sum) {
                std::cout<<"["<<i<<" "<<j<<"]";
                return;
            }
        }
    }
}

int main() {
    int arr[]{1, 4, 20, 3, 10, 5};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    FindGivenSum(A.getArray(), A.getSize(), 33);
    return 0;
}
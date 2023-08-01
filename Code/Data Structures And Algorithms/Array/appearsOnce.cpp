//Given an array of integers. All numbers occur twice except one number which occurs once.
//Find the number in O(N) time & constant extra space.

#include <iostream>
#include "array.h"

//Since a XOR b = 0 if a = b
//Time Complexity: O(N)
//Space Complexity: O(1)
int singleElement(int A[], int size) {
    int res = 0;
    for (int i=0; i<size; i++) {
        res = res ^ A[i];
    }
    if (!res) {return -1;}
    return res;
}

int main() {
    int arr[]{2, 3, 5, 4, 5, 3, 4};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    std::cout<<singleElement(A.getArray(), A.getSize());
    return 0;
}
//Given a sorted array of N elements and a number, Find out if the number appears more than N/2 times in the array.
#include <iostream>
#include "array.h"

//If the element first occurrs at i then check if it also occurs at i+size/2.
//Time Complexity: O(N)
//Space Complexity: O(1)
bool isMajority(int A[], int size, int K) {
    int i=0;
    int mid = size % 2 ? (size / 2 + 1): (size / 2);
    while (i < mid) {
        if (A[i] == K && A[mid+i] == K) return 1;
        i++;
    }
    return 0;
}

int main() {
    int arr[]{1, 1, 2, 4, 4, 4, 6, 6};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    int x = 4;
    std::cout<<(isMajority(A.getArray(), A.getSize(), x) ? "True" : "False");
    return 0;
}
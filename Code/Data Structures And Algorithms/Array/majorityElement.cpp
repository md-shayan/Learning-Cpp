//Find the majority element in the array. A majority element in an array A[] of size n is an element that appears
//more than n/2 times (and hence there is at most one such element). 
#include <iostream>
#include "array.h"

//Boyer-Moore's Voting Algorithm
//Time Comeplexity: O(N)
//Space Complexity: O(1)
int findMajority(int A[], int size) {
    int votes = 0;
    int candidate = -1;
    for (int i=0; i<size; i++) {
        if (votes == 0) {
            candidate = A[i];
            votes = 1;
        }
        else {
            if (A[i] == candidate) {
                votes++;
            }
            else {
                votes--;
            }
        }
    }
    int count=0;
    for (int j=0; j<size; j++) {
        if (A[j] == candidate) {
            count++;
        }
    }
    if (count > size/2) {return candidate;}
    return -1;
}

int main() {
    int arr[]{3, 4, 3, 2, 4, 4, 4, 4};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    std::cout<<findMajority(A.getArray(), A.getSize());
    return 0;
}
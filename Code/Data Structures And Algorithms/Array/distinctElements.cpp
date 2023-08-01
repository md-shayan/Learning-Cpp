//Given an integer array, print all distinct elements in an array.

#include <iostream>
#include "array.h"

//Time Complexity: O(N^2)
//Space Complexity: O(1)
void distinctElements(int A[], int size) {
    for (int i=0; i<size; i++)
    {
        int j;
        for (j=0; j<i; j++) {
           if (A[i] == A[j]) {break;}
        }
        if (i == j) {
          std::cout << A[i] << " ";
        }
    }
}

int main() {
    int arr[]{12, 10, 9, 45, 2, 10, 10, 45};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    distinctElements(arr, size);
    return 0;
}
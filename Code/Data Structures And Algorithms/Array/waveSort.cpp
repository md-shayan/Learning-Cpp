//Given an unsorted array of integers, sort the array into a wave array.
#include <iostream>
#include "array.h"

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//Time Complexity: O(N)
//Space Complexity: O(1)
void sortWave(int A[], int size) {
    for (int i=1; i<size-1; i++) {
        if (i%2!=0) {
            if (!(A[i-1] >= A[i])) {
                swap(A[i-1], A[i]);
            }
            else if (!(A[i] <= A[i+1])) {
                swap(A[i], A[i+1]);
            }
        }
    }
}


int main() {
    int arr[]{20, 10, 8, 6, 4, 2};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    A.print();
    sortWave(A.getArray(), A.getSize());
    A.print();
    return 0;
}
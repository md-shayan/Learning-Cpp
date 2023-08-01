//Given an array arr[] of size N, the task is to rotate the array by d position to the left.
#include <iostream>
#include "array.h"

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//Time Complexity: O(N)
//Space Complexity: O(1)
void reverse(int A[], int start, int end) {
    if (start <= end) {
        swap(A[start], A[end-1]);
        reverse(A, start+1, end-1);
    }
}

//Time Complexity: O(N)
//Space Complexity: O(1)
void shiftArray(int A[], int size, int K) {
    //Reverse the first K elements
    reverse(A, 0, K);
    //Reverse the rest of the array
    reverse(A, K, size);
    //Reverse the whole array
    reverse(A, 0, size);
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
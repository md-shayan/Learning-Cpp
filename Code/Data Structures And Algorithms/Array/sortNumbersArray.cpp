//You have given an array which contain 1 to n element,
//your task is to sort this array in an efficient way and without replace with 1 to n numbers.
#include <iostream>
#include "array.h"

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//Time Complexity: O(N)
//Space Complexity: O(1)
void sortNumbersArray(int A[], int size) {
    for (int i=0; i<size; i++) {
        A[i] = i+1;
    }
}

int main() {
    int arr[]{10, 7, 9, 2, 8, 3, 5, 4, 6, 1};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    A.print();
    sortNumbersArray(A.getArray(), A.getSize());
    A.print();
    return 0;
}
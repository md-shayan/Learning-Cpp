//Given a sequence arr[] of size n, Write a function int equilibrium(int[] arr, int n)
//that returns an equilibrium index (if any) or -1 if no equilibrium index exists.
//The equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the
//sum of elements at higher indexes. 
#include <iostream>
#include "array.h"

int equilibrium(int A[], int size) {
    int Left = 0;
    int Sum=0;
    for (int i=0; i<size; i++) {
        Sum+=A[i];
    }
    for (int j=0; j<size; j++) {
        Sum -= A[j];
        if (Sum == Left) return j;
        Left += A[j];
    }
    return -1;
}

int main() {
    int arr[]{1, 7, 3, 6, 5, 6};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    std::cout<<equilibrium(A.getArray(), A.getSize());
    return 0;
}
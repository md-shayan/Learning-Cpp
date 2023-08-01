#include <iostream>
#include "array.h"

void merge(int A[], int start, int mid, int end) {
    int leftSize = mid-start+1;
    int rightSize = end-mid;

    int* Left = new int[leftSize];
    int* Right = new int[rightSize];
    
    for (int i=0; i<leftSize; i++) {Left[i] = A[start + i];}
    for (int j=0; j<rightSize; j++) {Right[j] = A[mid+j+1];}
    
    int leftIndex = 0;
    int rightIndex = 0;
    int mainIndex = start;
    
    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (Left[leftIndex] <= Right[rightIndex]) {
            A[mainIndex] = Left[leftIndex];
            leftIndex++;
        }
        else {
            A[mainIndex] = Right[rightIndex];
            rightIndex++;
        }
        mainIndex++;
    }
    
    while (leftIndex < leftSize) {
        A[mainIndex] = Left[leftIndex];
        leftIndex++;
        mainIndex++;
    }
    
    while (rightIndex < rightSize) {
        A[mainIndex] = Right[rightIndex];
        rightIndex++;
        mainIndex++;
    }
    delete[] Left;
    delete[] Right;
}

void mergeSort(int A[], int start, int end) {
    if (start < end) {
        int mid = (start+end) / 2;
        mergeSort(A, 0, mid);
        mergeSort(A, mid+1, end);
        merge(A, start, mid, end);
    }
}


int main() {
    int arr[]{2, 1, 5, 4, 3};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    A.print();
    mergeSort(A.getArray(), 0, A.getSize());
    A.print();
    return 0;
}
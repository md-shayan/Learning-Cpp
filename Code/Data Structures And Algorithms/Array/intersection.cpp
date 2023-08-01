//Given three Sorted arrays in non-decreasing order, print all common elements in these arrays.
#include <iostream>
#include "array.h"

//Using Three-pointers technique.
//Time Compexity: O(N1 + N2 + N3) where N1, N2, N3 are the sizes of array A, B and C respectively.
//Space Complexity: O(1)
void findIntersection(int A[], int B[], int C[], int sizeA, int sizeB, int sizeC) {
    int i=0;
    int j=0;
    int k=0;
    while (i < sizeA && j < sizeB && k < sizeC) {
        if (A[i] > B[j]) {j++;}
        if (A[i] > C[k]) {k++;}
        if (B[j] > A[i]) {i++;}
        if (B[j] > C[k]) {k++;}
        if (C[k] > A[i]) {i++;}
        if (C[k] > B[j]) {j++;}
        if (A[i] == B[j] && B[j] == C[k]) {
            std::cout<<A[i]<<" ";
            i++;
            j++;
            k++;

        }
    }
}

int main() {
    int arr1[]{1, 5, 10, 20, 40, 80};
    int arr2[]{6, 7, 20, 80, 100};
    int arr3[]{3, 4, 15, 20, 30, 70, 80, 120};
    int sizeA = sizeof(arr1) / sizeof(int);
    int sizeB = sizeof(arr2) / sizeof(int);
    int sizeC = sizeof(arr3) / sizeof(int);
    Array<int> A(arr1, sizeA);
    Array<int> B(arr2, sizeB);
    Array<int> C(arr3, sizeC);
    findIntersection(A.getArray(), B.getArray(), C.getArray(), A.getSize(), B.getSize(), C.getSize());
    return 0;
}
//Given an unsorted array of positive integers, find the number of triangles that can be formed
//with three different array elements as three sides of triangles.
#include <iostream>
#include "array.h"

//Use three pointers, i=0, j=1, k=2 from k=0 to A.size
//if A[i] + A[j] > A[k] && A[i] + A[k] > A[j] && A[j] + A[k] > A[i], add one triangle.
//else if k+1 < size, increment k
//else if j+1 < size, increment j and set k=j+1
//else increment i and set j=i+1, k=i+2
//return answer
//Time Complexity: O(N^3)
//Space Complexity: O(1)
int possibleTriangles(int A[], int size) {
    int i=0;
    int j=1;
    int k=2;
    int ans = 0;
    while (k < size) {
        if (A[i] + A[j] > A[k] && A[i] + A[k] > A[j] && A[j] + A[k] > A[i]) {ans++;}
        if (k+1 < size) {
            k++;
        }
        else if (j+2 < size) {
            j++;
            k=j+1;
        }
        else {
            i++;
            j=i+1;
            k=i+2;
        }
    }
    return ans;
}

int main() {
    int arr[]{4, 6, 3, 7};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    std::cout<<possibleTriangles(A.getArray(), A.getSize());
    return 0;
}
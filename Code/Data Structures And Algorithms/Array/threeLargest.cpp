//Given an array with all distinct elements, find the largest three elements.
//Expected time complexity is O(n) and extra space is O(1). 
#include <iostream>
#include "array.h"

//Time Complexity: O(N) [Non-nested loops]
//Space Complexity: O(1)
int* threeLargest(int A[], int size) {
    int max1 = INT32_MIN;
    for (int i=0; i<size; i++) {
        if (A[i] > max1) {
            max1 = A[i];
        }
    }
    int max2 = INT32_MIN;
    for (int i=0; i<size; i++) {
        if (A[i] > max2 && A[i] < max1) {
            max2 = A[i];
        }
    }
    int max3 = INT32_MIN;
    for (int i=0; i<size; i++) {
        if (A[i] > max3 && A[i] < max1 && A[i] < max2) {
            max3 = A[i];
        }
    }
    int* max = new int[3];
    max[0] = max1;
    max[1] = max2;
    max[2] = max3;
    return max;
}

int main() {
    int arr[]{10, 4, 3, 50, 23, 90};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    int* ans = threeLargest(A.getArray(), A.getSize());
    Array<int> res(ans, 3);
    res.print();
    return 0;
}
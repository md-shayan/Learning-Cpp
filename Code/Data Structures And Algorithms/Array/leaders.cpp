//Write a program to print all the LEADERS in the array
//An element is a leader if it is greater than all the elements to its right side
//And the rightmost element is always a leader.
#include <iostream>
#include "array.h"

//Scan the array from last and keep a variable to store the maximum value and print it.
//Time Complexity: O(N)
//Space Complexity: O(1)
void leaders(int A[], int size) {
    int i=size-1;
    int leader = INT32_MIN;
    while (i > 0) {
        if (A[i] > leader) {
            leader = A[i];
            std::cout<<leader<<" ";
        }
        i--;
    }
}

int main() {
    int arr[]{16, 17, 4, 3, 5, 2};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    leaders(A.getArray(), A.getSize());
    return 0;
}
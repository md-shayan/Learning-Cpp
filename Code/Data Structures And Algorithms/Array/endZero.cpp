//Given an array of random numbers, Push all the zero’s of a given array to the end of the array
//The order of all other elements should be same. Expected time complexity is O(n) and extra space is O(1).
#include <iostream>
#include "array.h"

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//Time Complexity: O(N)
//Space Complexity: O(1)
void moveZeroes(int A[], int size) {
    //Use a variable lastZero to store the index of 0 the first time it appeared in a series of elements.
    int lastZero = 0;
    //Go through the array iteratively
    for (int i=0; i<size; i++) {
        //If the element is 0 and it is the first time it occured, set lastZero to the current indice.
        if (A[i] == 0 && !lastZero) {
            lastZero = i;
        }
        //Else if current element is non-zero and zero has appeared before, swap both of them and increment lastZero.
        else if (A[i] != 0 && lastZero) {
            swap(A[i], A[lastZero]);
            lastZero++;
        }
    }
}

int main() {
    int arr[]{1, 2, 0, 0, 0, 3, 6};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    A.print();
    moveZeroes(A.getArray(), A.getSize());
    A.print();
    return 0;
}
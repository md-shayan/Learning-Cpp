//Given an array arr[] of integers, segregate even and odd numbers in the array such that
//all the even numbers should be present first, and then the odd numbers.

#include <iostream>
#include "array.h"

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//Time Complexity: O(N)
//Space Comeplexity: O(1)
void segregateOddEven(int A[], int size) {
    int i=0;
    //Use a variable lastOdd to keep the index of the last odd value
    int lastOdd = -1;
    //Iterate over the array A
    while (i < size) {
        //If the current element is even and lastOdd is not -1, swap A[i] & A[lastOdd] and increment lastOdd
        if (A[i]%2==0 && lastOdd != -1) {
            swap(A[i], A[lastOdd]);
            lastOdd++;
        }
        //Else if current element is odd and lastOdd is -1, set lastOdd = i
        else if (A[i]%2!=0 && lastOdd == -1) {
            lastOdd = i;
        }
        i++;
    }
    //After the loop ends, swap A[lastOdd] with the last element of A
    swap(A[lastOdd], A[size-1]);
}


int main() {
    int arr[]{7, 2, 9, 4, 6, 1, 3, 8, 5 };
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    A.print();
    segregateOddEven(A.getArray(), A.getSize());
    A.print();
    return 0;
}
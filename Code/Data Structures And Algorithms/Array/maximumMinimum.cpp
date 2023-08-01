//Given a sorted array of positive integers, rearrange the array alternately i.e first element should be a maximum value,
//at second position minimum value, at third position second max, at fourth position second min, and so on. 
#include <iostream>
#include "array.h"

//Time Complexity: O(N)
//Space Complexity: O(N)
void maximumMinimum(int A[], int size) {
    int i=0;
    int j=size-1;
    //Declare a temp array of same size.
    int* ans = new int[size];
    int k=0;
    //Iterate over array A.
    while (k < size) {
        //If current index is divisible by 2, then store the last value, else store the first value.
        if (k%2==0) {
            ans[k] = A[j];
            j--;
        }
        else {
            ans[k] = A[i];
            i++;
        }
        k++;
    }
    //Copy the tem array back into A
    for (int i=0; i<size; i++) {
        A[i] = ans[i];
    }
}


int main() {
    int arr[]{1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    A.print();
    maximumMinimum(A.getArray(), A.getSize());
    A.print();
    return 0;
}
//Given an array A of non-negative integers and an integer sum, find a subarray that adds to a given sum.

#include <iostream>
#include "array.h"

//Using Sliding Window Technique,
//Declare a variable to keep track of the sum so far initialized to A[start] where start=0.
//Keep adding A[i], i=1,2,3... until it is less than the given sum.
//If the sum of subArray exceeds that of the given sum, then subtract A[start] and increment start by 1.
//Time Complexity: O(N)
//Space Complexity: O(1)
void FindGivenSum(int A[], int size, int sum) {
    int start=0;
    int currentSum=A[0];
    for (int i=1; i<=size; i++) {
        while (currentSum > sum && start<i-1) {
            currentSum = currentSum - A[start];
            start++;
        }
        if (currentSum == sum) {
            std::cout<<"["<<start<<" "<<i-1<<"]";
            return;
        }
        if (i < size) {
            currentSum = currentSum + A[i];
        }
    }
    std::cout<<"No subArray Found";
    return;
}

int main() {
    int arr[]{1, 4, 20, 3, 10, 5};
    int size = sizeof(arr) / sizeof(int);
    Array<int> A(arr, size);
    FindGivenSum(A.getArray(), A.getSize(), 33);
    return 0;
}

/*
 * Pseudocode for Linear Search            Cost           Running Time
 * for i=1 to A.length                      C1                N-1
 *     if A[i] == K                         C2                N-1
 *         return i                         C3                 1
 * return -1                                C4                 1
 * Best Case: ∅(1)
 * Worst Case: ∅(N)
*/
#include <iostream>

int linearSearch(int arr[], int size, int K) {
    for (int i=0; i<size; i++) {
        if (arr[i] == K) return i;
    }
    return -1;
}
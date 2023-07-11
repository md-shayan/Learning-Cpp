/*
 * Psuedocode for selection Sort               Cost                     Running Time
 * for i=1 to A.length                          C1                            N
 *     min = i                                  C2                           N-1
 *     for j=i to A.length                      C4                    ∑(N-i) for i=1 to N
 *         if A[j] < A[min]                     C5                  ∑[N(N-i)] for i=1 to N
 *             min = j                          C6                  ∑[N(N-i)] for i=1 to N
 *     temp = A[i]                              C8                           N-1
 *     A[i] = A[min]                            C9                           N-1
 *     A[min] = temp                            C10                          N-1
 * Best Case: N
 * Worst Case: N^2
*/
#include <iostream>

void SelectionSort(int arr[], int size) {
    int i=0;
    while(i < size) {
        int min = i;
        int j=i;
        while (j < size) {
            if (arr[j] < arr[min]) {
                min = j;
            }
            j++;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        i++; 
    }
}

void printArray(int arr[], int size) {
    int i=0;
    while (i < size) {
        std::cout<<arr[i]<<", ";
        i++;
    }
    std::cout<<std::endl;
}

int main() {
    int arr[]{5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    SelectionSort(arr, size);
    printArray(arr, size);
    return 0;
}
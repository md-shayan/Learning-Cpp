#include <iostream>

void InsertionSort(int arr[], int size) {
    int i=1;
    while (i < size) {
        int key = arr[i];
        int j=i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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
    InsertionSort(arr, size);
    printArray(arr, size);
    return 0;
}
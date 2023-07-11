#include <iostream>

void reverseInsertionSort(int arr[], int size) {
    for (int i=1; i<size; i++) {
        int key = arr[i];
        int j = i-1;
        while (j>=0 && key>arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int size) {
	int i=0;
	while (i<size) {
		std::cout<<arr[i]<<", ";
		i++;
	}
	std::cout<<std::endl;
}

int main() {
	int arr[]{31, 41, 59, 26, 41, 58};
	int size = sizeof(arr) / sizeof(int);
	printArray(arr, size);
	reverseInsertionSort(arr, size);
	printArray(arr, size);
	return 0;
}
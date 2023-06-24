/*
 * Shifts the first d elements of the given array to the end of the array by storing the elements in a temp array.
 * Time Complexity: O(N)
 * Space Complexity: O(N)
*/

#include <iostream>

void shift(int arr[], int d, int size)
{
    int temp[size];
    int k=0;

    for (int i=d; i<size; i++)
    {
        temp[k] = arr[i];
        k++;
    }

    for (int i=0; i<d; i++)
    {
        temp[k] = arr[i];
        k++;
    }

    for (int i=0; i<size; i++)  arr[i] = temp[i];
}

void printArray(int arr[], int size)
{
    for (int i=0; i<size; i++) std::cout<<arr[i];
    std::cout<<std::endl;
}

int main()
{
    int arr[]{1, 2, 3, 4, 5};
    printArray(arr, 5);
    shift(arr, 2, 5);
    printArray(arr, 5);
    return 0;
}
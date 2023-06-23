/*
 * Reverses a given array arr of size N using a temp array.
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

#include <iostream>

void reverse(int arr[], int size)
{
    int temp[size];
    int k=0;

    for (int i=size-1; i>=0; i--)
    {
        temp[k] = arr[i];
        k++;
    }
    
    for (int i=0; i<size; i++)
    {
        arr[i] = temp[i];
    }
}

void printArray(int arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        std::cout<<arr[i];
    }
    std::cout<<std::endl;
}

int main()
{
    int arr[]{1, 2, 3, 4};
    printArray(arr, 4);
    reverse(arr, 4);
    printArray(arr, 4);
    return 0;
}
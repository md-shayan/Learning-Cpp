/*
 * Shifts the first d elements of given array to the end of the array.
 * It picks an element moves the array towards left by one and places the element at the end. This is done d times.
 * Time Complexity: O(N*d)
 * Space complexity: O(1)
*/

#include <iostream>

void shift(int arr[], int d, int size)
{
    for (int i=0; i<d; i++)
    {
        int temp = arr[0];
        for (int j=0; j<size; j++)
        {
            arr[j] = arr[j+1];
        }
        arr[size-1] = temp;
    }  
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
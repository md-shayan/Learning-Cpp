/*
 * Reverses a given array arr of size N from arr[first] till arr[last] using recursion
 * Time Complexity: O(N)
 * Space Complexity: O(1)
*/

#include <iostream>

void reverse(int arr[], int first, int last)
{
    last--;
    if (first >= last)
    {
        ;
    }
    else{
        int temp = arr[last];
        arr[last] = arr[first];
        arr[first] = temp;
        reverse(arr, first+1, last);
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
    int arr[]{1, 2, 3, 4, 5};
    printArray(arr, 5);
    reverse(arr, 0, 5);
    printArray(arr, 5);
    return 0;
}
#include <iostream>
#include "Stack.h"

// Time Complexity: O(N)
// Space Complexity: O(N)
template <typename T>
Stack<T>* monotonicStack(T* arr, int size) {
    Stack<T>* stack = new Stack<T>(size);
    stack->push(arr[0]);
    for (int i = 1; i < size; i++) {
        if (stack->top() > arr[i]) {
            while (stack->top() > arr[i]) {
                stack->pop();
            }
            stack->push(arr[i]);
        }
        else {
            stack->push(arr[i]);
        }
    }
    return stack;
}

int main() {
    int arr[]{0, 2, 1, 4, 2, 6, 3, 8, 4, 10, 5, 12, 6, 14, 7, 16, 8, 18, 9, 20, 10};
    int size = sizeof(arr) / sizeof(int);
    Stack<int>* stack;
    stack = monotonicStack(arr, size);
    stack->print();
}
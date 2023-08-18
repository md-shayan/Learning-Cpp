#include <iostream>

namespace Algorithms {
    namespace Searching {}
}

namespace Algorithms::Searching {
    template <typename T>
    int Linear_Search(T* arr, int size, T target) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {return i;}
        }
        return -1;
    }

    template <typename T>
    int Binary_Search(T* arr, int low, int high, T target) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {return mid;}
        if (arr[mid] > target) {return Binary_Search(arr, mid+1, high, target);}
        if (arr[mid] < target) {return Binary_Search(arr, low, mid-1, target);}
        return -1;
    }
};

int main() {
    using Algorithms::Searching::Linear_Search;
    int arr[]{5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(int);
    std::cout << Linear_Search<int>(arr, size, 2) << std::endl;
    return 0;
}
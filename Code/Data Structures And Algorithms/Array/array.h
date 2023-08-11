#include <iostream>

template<typename T>
struct Array {
    //Time Complexity: O(1)
    Array() = default;

    //Time Complexity: O(1)
    Array(int size) : arrSize{size} {
        arr = new T[arrSize];
    }

    //Time Complexity: O(1)
    Array(T* array, int size) : arrSize{size} {
        arr = new T[arrSize];
        arr = array;
    }

    //Time Complexity: O(1)
    void setSize(int newSize) {
        if (newSize == arrSize) {}
        else {
            arrSize = newSize;
            Array(arr, newSize);
        }
    }

    //Time Complexity: O(1)
    int getSize() {
        return arrSize;
    }

    T* getArray() {
        return arr;
    }

    //Time Complexity: O(N)
    void insert(T elem, int index) {
        //Needs to insert at the end of array
        if (index == arrSize) {
            setSize(arrSize+1);
            arr[arrSize-1] = elem;
        }
        else {
            setSize(arrSize+1);
            //Shifts all the elements from arr[index to arrSize] one index right
            int i = arrSize;
            while (i > index) {
                arr[i] = arr[i-1];
                i--;
            }
            arr[index] = elem;
        }
    }

    //Time Complexity: O(N)
    int search(T elem) {
        for (int i=0; i<arrSize; i++) {
            if (arr[i] == elem) {
                return i;
            }
        }
        return -1;
    }

    //Time Complexity: O(N)
    void deleteElem(T elem) {
        // Find the index of the element to be deleted
        int index = search(elem);
        if (index == -1) {
            elemNotFoundError(elem);
        }
        //Last element is to be deleted
        if (index == arrSize-1) {
            setSize(arrSize-1);
        }
        else {
            // Move all the elements from arr[index to arrSize] one index left
            for (int i=index; i<arrSize; i++) {
                arr[i] = arr[i+1];
            }
            setSize(arrSize-1);
        }
    }

    //Time Complexity: O(N)
    //Space Complexity: O(N)
    void Merge(int start, int mid, int end) {
        int leftSize = mid-start+1;
        int rightSize = end-mid;

        T* Left = new T[leftSize];
        T* Right = new T[rightSize];

        for (int i=0; i<leftSize; i++) {Left[i] = arr[start+i];}
        for (int j=0; j<rightSize; j++) {Right[j] = arr[j+mid+1];}
        int leftIndex = 0;
        int rightIndex = 0;
        int mainIndex = start;
        while (leftIndex < leftSize && rightIndex < rightSize) {
            if (Left[leftIndex] >= Right[rightIndex]) {
                arr[mainIndex] = Right[rightIndex];
                rightIndex++;
            }
            else {
                arr[mainIndex] = Left[leftIndex];
                leftIndex++;
            }
            mainIndex++;
        }

        while (leftIndex < leftSize) {
            arr[mainIndex] = Left[leftIndex];
            mainIndex++;
            leftIndex++;
        }

        while (rightIndex < rightSize) {
            arr[mainIndex] = Right[rightIndex];
            rightIndex++;
            mainIndex++;
        }

        delete[] Left;
        delete[] Right;
    }

    //Time Complexity: (N*log₂N)
    //Space Complexity: O(N)
    void Sort(int start, int end) {
        if (start < end) {
            int mid = (start+end)/2;
            Sort(0, mid);
            Sort(mid+1, end);
            Merge(start, mid, end);
        }
    }

    //Time Complexity: O(1)
    void swap(int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    //Time Complexity: O(N)
    void print() {
        for (int i=0; i<arrSize; i++) {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
    }

    void outOfRangeError(int size) {
        std::cout<<"outOfRangeError: index "<<size<<" is out of array object";
    }
    
    void elemNotFoundError(int elem) {
        std::cout<<"elemNotFoundError: element "<<elem<<" not found in array";
    }
private:
    int arrSize;
    T* arr = nullptr;
};
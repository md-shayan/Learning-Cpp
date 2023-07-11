#include <iostream>

void Merge(int A[], int P, int Q, int R) {
    int Lsize = Q-P+1;
    int Rsize = R-Q;
    int* Left = new int[Lsize];
    int* Right = new int[Rsize];

    int i=0;
    while (i < Lsize) {
        Left[i] = A[P+i];
        i++;
    }

    int j=0;
    while (j < Rsize) {
        Right[j] = A[Q+j+1];
        j++;
    }

    int indexL = 0;
    int indexR = 0;
    int indexA = P;
    while (Lsize > indexL && Rsize > indexR) {
        if (Left[indexL] <= Right[indexR]) {
            A[indexA] = Left[indexL];
            indexL++;
        }
        else {
            A[indexA] = Right[indexR];
            indexR++;
        }
        indexA++;
    }

    while (Lsize > indexL) {
        A[indexA] = Left[indexL];
        indexL++;
        indexA++;
    }

    while (Rsize > indexR) {
        A[indexA] = Right[indexR];
        indexR++;
        indexA++;
    }

    delete[] Left;
    delete[] Right;
}

void printArray(int A[], int size) {
    int i=0;
    while (i < size) {
        std::cout<<A[i]<<", ";
        i++;
    }
    std::cout<<std::endl;
}

void MergeSort(int A[], int P, int R) {
    if (P < R) {
        int Q = (P+R) / 2;
        MergeSort(A, P, Q);
        MergeSort(A, Q+1, R);
        Merge(A, P, Q, R);
    }
}

int main() {
    int A[]{5, 6, 1, 2, 7, 8, 3, 4, 9, 10};
    int size = sizeof(A) / sizeof(int);
    printArray(A, size);
    MergeSort(A, 0, size);
    printArray(A, size);
    return 0;
}
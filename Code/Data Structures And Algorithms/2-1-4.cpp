#include <iostream>

void addBinary(int A[], int B[], int size, int C[]) {
    int i=size-1;
    int j=0;
    int carry = 0;
    C[0] = 0;
    while (i >= j) {
        if (carry) {
            if (A[i] && B[i]) {
                C[i+1] = 1;
                carry = 1;
            }
            else if (A[i] || B[i]) {
                C[i+1] = 0;
                carry = 1;
            }
            else if (!A[i] && !B[i]) {
                C[i+1] = 1;
                carry = 0;
            }
        }
        else {
            if (A[i] && B[i]) {
                C[i+1] = 0;
                carry = 1;
            }
            else if (A[i] || B[i]) {
                C[i+1] = 1;
                carry = 0;
            }
            else if (!A[i] && !B[i]) {
                C[i+1] = 0;
                carry = 0;
            }
        }
        i--;
        }
        if (carry) C[0] = 1;
    }

int main() {
    int A[]{1, 1, 1, 0, 1};
    int B[]{1, 0, 1, 0, 0};
    int n = sizeof(A) / sizeof(int);
    int C[n+1];
    addBinary(A, B, n, C);
    for (int i=0; i<n+1; i++) std::cout<<C[i];
}
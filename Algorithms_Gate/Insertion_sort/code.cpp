#include <iostream>
using namespace std;

void insertionSort(int A[], int n) {

    for (int i = 1; i < n; i++) {

        int key = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = key;
    }
}

int main() {

    int A[] = {5, 3, 8, 2, 4};
    int n = 5;

    insertionSort(A, n);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}
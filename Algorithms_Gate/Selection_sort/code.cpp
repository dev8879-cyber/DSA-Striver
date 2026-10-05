#include <iostream>
using namespace std;

void selectionSort(int A[], int n) {

    for (int pass = 1; pass <= n - 1; pass++) {

        int min_ind = pass;

        for (int j = pass + 1; j <= n; j++) {

            if (A[j] < A[min_ind]) {
                min_ind = j;
            }
        }

        swap(A[pass], A[min_ind]);
    }
}

int main() {

    int A[] = {0, 5, 3, 8, 2, 4};  // A[0] unused
    int n = 5;

    selectionSort(A, n);

    for (int i = 1; i <= n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}
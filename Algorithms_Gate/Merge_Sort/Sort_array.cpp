#include <iostream>
using namespace std;

void merge(int A[], int low, int mid, int high)
{
    int B[100];

    int h = low;
    int j = mid + 1;
    int i = low;

    while (h <= mid && j <= high)
    {
        if (A[h] <= A[j])
        {
            B[i] = A[h];
            h++;
        }
        else
        {
            B[i] = A[j];
            j++;
        }

        i++;
    }

    // Remaining left part
    while (h <= mid)
    {
        B[i] = A[h];
        h++;
        i++;
    }

    // Remaining right part
    while (j <= high)
    {
        B[i] = A[j];
        j++;
        i++;
    }

    // Copy back
    for (int k = low; k <= high; k++)
    {
        A[k] = B[k];
    }
}

void mergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(A, low, mid);

        mergeSort(A, mid + 1, high);

        merge(A, low, mid, high);
    }
}

int main()
{
    int A[] = {20, 10, 50, 7, 40, 80, 30, 100, 15, 8};

    int n = sizeof(A) / sizeof(A[0]);

    mergeSort(A, 0, n - 1);

    cout << "Sorted Array:\n";

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
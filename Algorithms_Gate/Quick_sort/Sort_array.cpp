#include <iostream>
using namespace std;

int partition(int A[], int low, int high)
{
    int pivot = A[low];

    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        // Find element greater than pivot
        while (i <= high && A[i] <= pivot)
        {
            i++;
        }

        // Find element smaller than pivot
        while (A[j] > pivot)
        {
            j--;
        }

        // Swap if needed
        if (i < j)
        {
            swap(A[i], A[j]);
        }
    }

    // Put pivot at correct position
    swap(A[low], A[j]);

    return j;
}

void quickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(A, low, high);

        quickSort(A, low, pivotIndex - 1);

        quickSort(A, pivotIndex + 1, high);
    }
}

int main()
{
    int A[] = {20, 10, 50, 7, 40, 80, 30};

    int n = sizeof(A) / sizeof(A[0]);

    quickSort(A, 0, n - 1);

    cout << "Sorted Array:\n";

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
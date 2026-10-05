#include <iostream>
using namespace std;

struct Pair {
    int min;
    int max;
};

Pair findMinMax(int arr[], int low, int high) {
    Pair result;

    // Only one element
    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }

    // Two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // Divide
    int mid = low + (high - low) / 2;

    Pair left = findMinMax(arr, low, mid);
    Pair right = findMinMax(arr, mid + 1, high);

    // Conquer / Combine
    result.min = min(left.min, right.min);
    result.max = max(left.max, right.max);

    return result;
}

int main() {
    int arr[] = {10, 5, 20, 3, 15, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    Pair result = findMinMax(arr, 0, n - 1);

    cout << "Minimum = " << result.min << endl;
    cout << "Maximum = " << result.max << endl;

    return 0;
}
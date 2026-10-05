#include <iostream>
using namespace std;

int query(int i) {
    cout << "? " << i << endl;

    int x;
    cin >> x;

    return x;
}

int main() {
    int n;
    cin >> n;

    int left = 1;
    int right = n;

    int leftValue = query(1);

    // n = 1
    if (n == 1) {
        cout << "! 1" << endl;
        return 0;
    }

    int rightValue = query(n);

    while (left <= right) {
        int mid = (left + right) / 2;

        int cur = query(mid);

        int prev;
        int next;

        if (mid == 1)
            prev = INT_MAX;
        else
            prev = query(mid - 1);

        if (mid == n)
            next = INT_MAX;
        else
            next = query(mid + 1);

        if (cur < prev && cur < next) {
            cout << "! " << mid << endl;
            return 0;
        }

        if (prev < cur) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return 0;
}
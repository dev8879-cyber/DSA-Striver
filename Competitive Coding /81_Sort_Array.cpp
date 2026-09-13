#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b = a;

    sort(b.begin(), b.end());

    int l = 0;

    while (l < n && a[l] == b[l]) {
        l++;
    }

    // Already sorted
    if (l == n) {
        cout << "yes\n";
        cout << "1 1\n";
        return 0;
    }

    int r = n - 1;

    while (a[r] == b[r]) {
        r--;
    }

    reverse(a.begin() + l, a.begin() + r + 1);

    if (a == b) {
        cout << "yes\n";
        cout << l + 1 << " " << r + 1 << "\n";
    } else {
        cout << "no\n";
    }

    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    double maxGap = 0;

    // Maximum gap between two consecutive lanterns
    for (int i = 1; i < n; i++) {
        maxGap = max(maxGap, (double)(a[i] - a[i - 1]));
    }

    double firstGap = a[0];
    double lastGap = l - a[n - 1];

    double answer = max({
        firstGap,
        lastGap,
        maxGap / 2.0
    });

    cout << answer << endl;

    return 0;
}
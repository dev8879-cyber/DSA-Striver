#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int min_val = 2e9 + 7;
    int min_idx = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < min_val) {
            min_val = a[i];
            min_idx = i;
        }
    }

    // Number of operations will be n - 1 (updating every element except min_idx)
    cout << n - 1 << "\n";

    for (int i = 0; i < n; i++) {
        if (i == min_idx) continue;
        
        // Output format: i, j, x, y (1-based indices)
        // Replacing a[i] with min_val + |i - min_idx| and keeping a[min_idx] as min_val
        cout << i + 1 << " " << min_idx + 1 << " " << min_val + abs(i - min_idx) << " " << min_val << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
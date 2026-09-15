#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Since 1 <= a[i] <= n, a direct lookup array is optimal
    vector<int> last_pos(n + 1, -1);
    int min_len = n + 2;

    for (int i = 0; i < n; ++i) {
        int val = a[i];
        if (last_pos[val] != -1) {
            min_len = min(min_len, i - last_pos[val] + 1);
        }
        last_pos[val] = i;
    }

    if (min_len > n) {
        cout << -1 << "\n";
    } else {
        cout << min_len << "\n";
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
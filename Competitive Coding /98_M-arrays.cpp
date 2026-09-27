#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> cnt(m, 0);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x % m]++;
        }

        int ans = 0;

        // Remainder 0
        if (cnt[0] > 0)
            ans++;

        // Pair r with m-r
        for (int r = 1; r < (m + 1) / 2; r++) {

            int x = cnt[r];
            int y = cnt[m - r];

            if (x == 0 && y == 0)
                continue;

            if (x == 0 || y == 0)
                ans += x + y;
            else
                ans += max(1, abs(x - y));
        }

        // Special case: m/2
        if (m % 2 == 0 && cnt[m / 2] > 0)
            ans++;

        cout << ans << '\n';
    }

    return 0;
}
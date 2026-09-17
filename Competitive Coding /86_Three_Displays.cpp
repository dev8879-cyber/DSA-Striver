#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> s(n), c(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) cin >> c[i];

    long long min_total_cost = INF;

    // Fix the middle element j
    for (int j = 1; j < n - 1; ++j) {
        long long min_left = INF;
        for (int i = 0; i < j; ++i) {
            if (s[i] < s[j]) {
                min_left = min(min_left, c[i]);
            }
        }

        long long min_right = INF;
        for (int k = j + 1; k < n; ++k) {
            if (s[k] > s[j]) {
                min_right = min(min_right, c[k]);
            }
        }

        if (min_left != INF && min_right != INF) {
            min_total_cost = min(min_total_cost, min_left + c[j] + min_right);
        }
    }

    if (min_total_cost == INF) {
        cout << -1 << "\n";
    } else {
        cout << min_total_cost << "\n";
    }

    return 0;
}
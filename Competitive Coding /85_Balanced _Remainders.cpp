#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> c(3, 0);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        c[val % 3]++;
    }

    int target = n / 3;
    int moves = 0;

    // Simulate cyclic shifting until all remainder counts equal target
    while (c[0] != target || c[1] != target || c[2] != target) {
        for (int i = 0; i < 3; ++i) {
            if (c[i] > target) {
                int excess = c[i] - target;
                moves += excess;
                c[(i + 1) % 3] += excess;
                c[i] = target;
            }
        }
    }

    cout << moves << "\n";
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
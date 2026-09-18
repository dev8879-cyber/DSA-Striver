#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int total_sum = 0;
    for (char c : s) {
        total_sum += (c - '0');
    }

    // Special case: all digits are '0'
    if (total_sum == 0) {
        cout << "YES\n";
        return;
    }

    // Check all possible segment sums S from 0 up to total_sum - 1
    for (int S = 0; S < total_sum; ++S) {
        if (S > 0 && total_sum % S != 0) {
            continue; // Total sum must be a multiple of S
        }

        int current = 0;
        int segments = 0;
        bool ok = true;

        for (int i = 0; i < n; ++i) {
            current += (s[i] - '0');
            if (current == S) {
                segments++;
                current = 0;
            } else if (current > S) {
                ok = false;
                break;
            }
        }

        // Must end cleanly with no leftover digits and at least 2 segments
        if (ok && current == 0 && segments >= 2) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
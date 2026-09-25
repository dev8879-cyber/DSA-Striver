#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        long long mini1 = a[0];
        long long mini2 = b[0];

        for(int i = 0; i < n; i++) {
            mini1 = min(mini1, a[i]);
            mini2 = min(mini2, b[i]);
        }

        long long moves = 0;

        for(int i = 0; i < n; i++) {

            long long x = a[i] - mini1;
            long long y = b[i] - mini2;

            // Decrease both together
            moves += min(x, y);

            // Remaining decrease individually
            moves += abs(x - y);
        }

        cout << moves << '\n';
    }

    return 0;
}
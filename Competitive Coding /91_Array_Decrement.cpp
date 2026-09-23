#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        long long k = -1;

        // Find k using a position where b[i] > 0
        for (int i = 0; i < n; i++) {
            if (b[i] > 0) {
                k = a[i] - b[i];
                break;
            }
        }

        bool possible = true;

        for (int i = 0; i < n; i++) {

            if (b[i] > 0) {
                // Difference must be the same
                if (a[i] - b[i] != k) {
                    possible = false;
                    break;
                }
            }
            else {
                // b[i] = 0
                // a[i] must become zero within k operations
                if (a[i] > k) {
                    possible = false;
                    break;
                }
            }
        }

        cout << (possible ? "YES" : "NO") << '\n';
    }

    return 0;
}
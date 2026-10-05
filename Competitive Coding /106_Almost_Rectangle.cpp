#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int r1, c1, r2, c2;
        bool found = false;

        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;

            for (int j = 1; j <= n; j++) {
                if (s[j - 1] == '*') {
                    if (!found) {
                        r1 = i;
                        c1 = j;
                        found = true;
                    } else {
                        r2 = i;
                        c2 = j;
                    }
                }
            }
        }

        if (r1 != r2 && c1 != c2) {
            // Different row and different column
            cout << r1 << " " << c2 << '\n';
            cout << r2 << " " << c1 << '\n';
        }
        else if (r1 == r2) {
            // Same row
            int r = (r1 == 1 ? 2 : 1);

            cout << r << " " << c1 << '\n';
            cout << r << " " << c2 << '\n';
        }
        else {
            // Same column
            int c = (c1 == 1 ? 2 : 1);

            cout << r1 << " " << c << '\n';
            cout << r2 << " " << c << '\n';
        }
    }

    return 0;
}
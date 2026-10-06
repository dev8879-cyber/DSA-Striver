#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        bool ok = false;

        for (int i = 0; i <= 4; i++) {
            string target = "2020";

            string left = target.substr(0, i);
            string right = target.substr(i);

            if (s.substr(0, i) == left &&
                s.substr(n - (4 - i)) == right) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}
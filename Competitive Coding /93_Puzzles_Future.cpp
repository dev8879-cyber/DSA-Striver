#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string b;
        cin >> b;

        string a = "";

        int prev = -1;

        for (int i = 0; i < n; i++) {

            if (b[i] == '0') {
                if (prev == 1) {
                    a += '0';
                    prev = 0;
                }
                else {
                    a += '1';
                    prev = 1;
                }
            }
            else {
                if (prev == 2) {
                    a += '0';
                    prev = 1;
                }
                else {
                    a += '1';
                    prev = 2;
                }
            }
        }

        cout << a << '\n';
    }

    return 0;
}
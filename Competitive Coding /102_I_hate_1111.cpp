#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;

        bool possible = false;

        for (int i = 0; i <= 10; i++) {
            if (x - i * 111 >= 0 &&
                (x - i * 111) % 11 == 0) {
                possible = true;
                break;
            }
        }

        if (possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string b;
        cin >> b;

        for (int i = 0; i < b.length(); i += 2) {
            cout << b[i];
        }

        if (b.length() % 2 == 0) {
            cout << b.back();
        }

        cout << '\n';
    }

    return 0;
}
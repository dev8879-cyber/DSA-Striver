#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (char c : s) {
        if (c == 'H' || c == 'Q' || c == '9' || c == '+') {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    bool is_colored = false;
    for (int i = 0; i < n * m; ++i) {
        char ch;
        cin >> ch;
        if (ch == 'C' || ch == 'M' || ch == 'Y') {
            is_colored = true;
        }
    }

    if (is_colored) {
        cout << "#Color\n";
    } else {
        cout << "#Black&White\n";
    }

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << (i % 2 ? "I hate" : "I love");

        if (i != n)
            cout << " that ";
    }

    cout << " it";

    return 0;
}
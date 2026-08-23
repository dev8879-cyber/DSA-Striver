#include <iostream>
using namespace std;

int main() {

    int n, k, t;
    cin >> n >> k >> t;

    int total = (n * k * t) / 100;

    int full = total / k;
    int partial = total % k;

    for (int i = 0; i < n; i++) {

        if (i < full)
            cout << k << " ";

        else if (i == full)
            cout << partial << " ";

        else
            cout << 0 << " ";
    }

    return 0;
}
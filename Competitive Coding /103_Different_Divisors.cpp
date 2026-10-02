#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int d;
        cin >> d;

        int p = d + 1;

        while (!isPrime(p))
            p++;

        int q = p + d;

        while (!isPrime(q))
            q++;

        cout << 1LL * p * q << '\n';
    }

    return 0;
}
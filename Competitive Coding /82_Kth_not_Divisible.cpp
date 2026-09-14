#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long q = (k - 1) / (n - 1);
        long long r = (k - 1) % (n - 1);

        long long ans = q * n + r + 1;

        cout << ans << '\n';
    }

    return 0;
}
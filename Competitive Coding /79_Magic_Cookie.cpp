#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    long long low = 0;
    long long high = 1e9;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        long long need = 0;

        for (int i = 0; i < n; i++) {
            long long required = a[i] * mid;

            if (required > b[i]) {
                need += required - b[i];
            }
        }

        if (need <= k) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
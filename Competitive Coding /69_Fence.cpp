#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int sum = 0;

    for (int i = 0; i < k; i++) {
        sum += h[i];
    }

    int miniSum = sum;
    int ans = 1;

    for (int i = k; i < n; i++) {
        sum += h[i];
        sum -= h[i-k];

        if (sum < miniSum) {
            miniSum = sum;
            ans = i-k+2;
        }
    }

    cout << ans << endl;

    return 0;
}
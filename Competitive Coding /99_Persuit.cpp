#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);

        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        // Highest scores first
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());

        // Prefix sums
        vector<int> preA(n + 1, 0), preB(n + 1, 0);

        for (int i = 0; i < n; i++) {
            preA[i + 1] = preA[i] + a[i];
            preB[i + 1] = preB[i] + b[i];
        }

        // Try adding x new stages
        for (int x = 0; ; x++) {

            int total = n + x;
            // Number of scores that count
            int cnt = total - total / 4;

            // We get 100 in all x new stages.
            // Remaining scores must come from our old scores.
            int takeA = cnt - x;

            int myScore = x * 100 + preA[takeA];

            // Ilya gets 0 in the new stages,
            // so only his old scores can contribute.
            int takeB = min(n, cnt);

            int ilyaScore = preB[takeB];

            if (myScore >= ilyaScore) {
                cout << x << '\n';
                break;
            }
        }
    }

    return 0;
}
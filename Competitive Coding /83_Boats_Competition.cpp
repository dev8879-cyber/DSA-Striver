#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int ans = 0;

        for (int s = 2; s <= 2 * n; s++) {

            int l = 0;
            int r = n - 1;
            int cnt = 0;

            while (l < r) {

                if (a[l] + a[r] == s) {
                    cnt++;
                    l++;
                    r--;
                }
                else if (a[l] + a[r] < s) {
                    l++;
                }
                else {
                    r--;
                }
            }

            ans = max(ans, cnt);
        }

        cout << ans << '\n';
    }

    return 0;
}
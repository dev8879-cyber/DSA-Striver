#include<iostream>
using namespace std;

using ll = long long;

ll countPairs(vector<ll>& a, ll x) {
    int n = a.size();
    ll cnt = 0;

    for (int i = 0; i < n; i++) {

        ll limit = x - a[i];

        int pos = upper_bound(
            a.begin() + i + 1,
            a.end(),
            limit
        ) - a.begin();

        cnt += pos - i - 1;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll l, r;

        cin >> n >> l >> r;

        vector<ll> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        ll ans = countPairs(a, r)
               - countPairs(a, l - 1);

        cout << ans << '\n';
    }

    return 0;
}
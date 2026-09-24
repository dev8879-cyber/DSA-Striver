#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);

        for(int &x : a)
            cin >> x;

        for(int &x : b)
            cin >> x;

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        for(int i = 0; i < k; i++) {
            if(a[i] < b[i])
                swap(a[i], b[i]);
            else
                break;
        }

        int ans = 0;

        for(int x : a)
            ans += x;

        cout << ans << '\n';
    }

    return 0;
}
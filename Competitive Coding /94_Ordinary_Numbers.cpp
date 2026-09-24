#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long n;
        cin >> n;

        int ans = 0;

        for(int d = 1; d <= 9; d++) {
            long long num = 0;

            while(num <= n) {
                num = num * 10 + d;

                if(num <= n)
                    ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
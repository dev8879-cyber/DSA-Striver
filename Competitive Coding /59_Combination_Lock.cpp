#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int diff = abs(s1[i] - s2[i]);

        ans += min(diff, 10 - diff);
    }

    cout << ans;

    return 0;
} 

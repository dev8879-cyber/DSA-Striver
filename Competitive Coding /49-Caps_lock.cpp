#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    char current = 'a';
    int ans = 0;

    for (char target : s) {
        int diff = abs(current - target);

        ans += min(diff, 26 - diff);

        current = target;
    }

    cout << ans;

    return 0;
}
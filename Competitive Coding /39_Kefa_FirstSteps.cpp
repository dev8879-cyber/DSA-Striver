#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int prev, curr;
    cin >> prev;

    int len = 1;
    int ans = 1;

    for(int i = 1; i < n; i++) {
        cin >> curr;

        if(curr >= prev) {
            len++;
        }
        else {
            len = 1;
        }

        ans = max(ans, len);
        prev = curr;
    }

    cout << ans;

    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;

    int minChessRight = 1e9;
    int maxChessLeft = -1;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        minChessRight = min(minChessRight, r);
        maxChessLeft = max(maxChessLeft, l);
    }

    int m;
    cin >> m;

    int minProgrammingRight = 1e9;
    int maxProgrammingLeft = -1;

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;

        minProgrammingRight = min(minProgrammingRight, r);
        maxProgrammingLeft = max(maxProgrammingLeft, l);
    }

    int ans = max(
        maxProgrammingLeft - minChessRight,
        maxChessLeft - minProgrammingRight
    );

    ans = max(ans, 0);

    cout << ans;

    return 0;
}
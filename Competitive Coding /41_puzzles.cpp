#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> puzzles(m);

    // Input puzzle sizes
    for (int i = 0; i < m; i++) {
        cin >> puzzles[i];
    }

    // Arrange from smallest to largest
    sort(puzzles.begin(), puzzles.end());

    int ans = 1000000;

    // Check every group of n consecutive puzzles
    for (int i = 0; i + n - 1 < m; i++) {

        // Last element - first element
        int difference = puzzles[i + n - 1] - puzzles[i];

        // Keep the minimum difference
        ans = min(ans, difference);
    }

    cout << ans;

    return 0;
}
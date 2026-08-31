#include <iostream>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> friends(n);

    for (int i = 0; i < n; i++) {
        cin >> friends[i].first >> friends[i].second;
    }

    sort(friends.begin(), friends.end());

    long long sum = 0;
    long long ans = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {

        sum += friends[right].second;

        // Invalid window
        while (friends[right].first - friends[left].first >= d) {
            sum -= friends[left].second;
            left++;
        }

        // Current window is valid
        ans = max(ans, sum);
    }

    cout << ans << '\n';

    return 0;
}
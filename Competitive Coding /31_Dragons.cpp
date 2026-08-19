#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<pair<int, int>> dragons(n);

    for (auto &[x, y] : dragons) {
        cin >> x >> y;
    }

    sort(dragons.begin(), dragons.end());

    for (auto [x, y] : dragons) {
        if (s <= x) {
            cout << "NO";
            return 0;
        }

        s += y;
    }

    cout << "YES";

    return 0;
}
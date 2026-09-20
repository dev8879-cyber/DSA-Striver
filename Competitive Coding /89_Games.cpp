#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> h(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i] >> a[i];
    }

    int count = 0;
    for (int host = 0; host < n; host++) {
        for (int guest = 0; guest < n; guest++) {
            if (host != guest && h[host] == a[guest]) {
                count++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}
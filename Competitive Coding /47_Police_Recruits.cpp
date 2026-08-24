#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int crimes = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int cnt;
        cin >> cnt;

        if (cnt == 1) {
            sum++;
        }
        else {
            if (sum > 0) {
                sum--;
            }
            else {
                crimes++;
            }
        }
    }

    cout << crimes;

    return 0;
}
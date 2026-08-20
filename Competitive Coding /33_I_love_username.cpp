#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int x;
    cin >> x;

    int maxi = x;
    int mini = x;
    int amazing = 0;

    for (int i = 1; i < n; i++) {
        cin >> x;

        if (x > maxi) {
            maxi = x;
            amazing++;
        }
        else if (x < mini) {
            mini = x;
            amazing++;
        }
    }

    cout << amazing;

    return 0;
}
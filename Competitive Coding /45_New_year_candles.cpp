#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int ans = a + (a - 1) / (b - 1);

    cout << ans;

    return 0;
}
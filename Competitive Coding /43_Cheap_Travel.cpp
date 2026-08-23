#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int normal = n * a;

    int mixed = (n / m) * b + (n % m) * a;

    int extra = ((n / m) + 1) * b;

    cout << min(normal, min(mixed, extra));

    return 0;
}
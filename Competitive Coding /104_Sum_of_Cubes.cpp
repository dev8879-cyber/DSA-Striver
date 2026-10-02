#include <iostream>
#include<set>
using namespace std;

int main() {
    int t;
    cin >> t;

    set<long long> cubes;

    // Store all possible cubes
    for (long long i = 1; i <= 10000; i++) {
        cubes.insert(i * i * i);
    }

    while (t--) {
        long long x;
        cin >> x;

        bool possible = false;

        for (long long i = 1; i <= 10000; i++) {
            long long cube = i * i * i;

            if (cube >= x)
                break;

            if (cubes.count(x - cube)) {
                possible = true;
                break;
            }
        }

        if (possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int police = 0;
    int crimes = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x > 0) {
            police += x;
        }
        else {
            if (police > 0) {
                police--;
            }
            else {
                crimes++;
            }
        }
    }

    cout << crimes << endl;

    return 0;
}
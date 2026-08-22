#include <iostream>
using namespace std;

int main() {
    int k, r;
    cin >> k >> r;

    for(int i = 1; i < 10; i++) {
        int show = k * i;

        if(show % 10 == r || show % 10 == 0) {
            cout << i;
            return 0;
        }
    }

    return 0;
}
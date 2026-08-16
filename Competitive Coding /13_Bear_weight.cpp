#include <iostream>
using namespace std;

int main() {

    int limak, bob;
    cin >> limak >> bob;

    int t = 0;

    while(limak <= bob) {

        t++;

        limak *= 3;
        bob *= 2;
    }

    cout << t;

    return 0;
}
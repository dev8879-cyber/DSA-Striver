#include <iostream>
using namespace std;

int main() {

    string s;
    cin >> s;

    int cnt = 0;

    // Count lucky digits
    for(char c : s) {

        if(c == '4' || c == '7') {
            cnt++;
        }
    }

    // Check whether cnt is lucky
    while(cnt > 0) {

        int digit = cnt % 10;

        if(digit != 4 && digit != 7) {
            cout << "NO";
            return 0;
        }

        cnt /= 10;
    }

    cout << "YES";

    return 0;
}
#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    int t = 0;

    for(int i = 0; i < n - 1; i++) {

        if(s[i + 1] == s[i]) {
            t++;
        }
    }

    cout << t;

    return 0;
}
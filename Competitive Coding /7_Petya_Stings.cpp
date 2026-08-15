#include <iostream>
#include <cctype>
using namespace std;

int main() {

    string s1, s2;

    cin >> s1 >> s2;

    for(int i = 0; i < s1.length(); i++) {

        char a = tolower(s1[i]);
        char b = tolower(s2[i]);

        if(a < b) {
            cout << -1;
            return 0;
        }

        if(a > b) {
            cout << 1;
            return 0;
        }
    }

    cout << 0;

    return 0;
}
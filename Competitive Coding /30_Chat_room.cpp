#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    string target = "hello";

    int j = 0;

    for(int i = 0; i < s.length(); i++) {

        if(s[i] == target[j]) {
            j++;
        }

        if(j == target.length()) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}
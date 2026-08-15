#include <iostream>
#include <cctype>
using namespace std;

int main() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    if(n < 26) {
        cout << "NO";
        return 0;
    }

    bool visited[26] = {};

    for(char c : s) {

        c = tolower(c);

        visited[c - 'a'] = true;
    }

    for(int i = 0; i < 26; i++) {

        if(!visited[i]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}
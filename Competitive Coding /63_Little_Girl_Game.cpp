#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int freq[26] = {0};

    for(char c : s) {
        freq[c - 'a']++;
    }

    int odd = 0;

    for(int i = 0; i < 26; i++) {
        if(freq[i] % 2 != 0)
            odd++;
    }

    if(odd == 0 || odd % 2 == 1)
        cout << "First";
    else
        cout << "Second";

    return 0;
}
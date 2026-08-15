#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    int score = 0;

    for(char c : s) {

        if(c == 'A')
            score++;
        else
            score--;
    }

    if(score > 0)
        cout << "Anton";
    else if(score < 0)
        cout << "Danik";
    else
        cout << "Friendship";

    return 0;
}
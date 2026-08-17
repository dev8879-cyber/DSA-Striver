#include <iostream>
#include <set>
using namespace std;

int main() {

    int n;
    cin >> n;

    set<int> levels;

    int p;
    cin >> p;

    for(int i = 0; i < p; i++) {
        int x;
        cin >> x;
        levels.insert(x);
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int y;
        cin >> y;
        levels.insert(y);
    }

    for(int i = 1; i <= n; i++) {
        if(levels.find(i) == levels.end()) {
            cout << "Oh, my keyboard!";
            return 0;
        }
    }

    cout << "I become the guy.";

    return 0;
}
#include <iostream>
#include<set>
#include<map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> mp = {
        {"Tetrahedron", 4},
        {"Cube", 6},
        {"Octahedron", 8},
        {"Dodecahedron", 12},
        {"Icosahedron", 20}
    };

    int ans = 0;

    while (n--) {
        string s;
        cin >> s;
        ans += mp[s];
    }

    cout << ans;
}
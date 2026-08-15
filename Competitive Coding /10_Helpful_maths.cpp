#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    string s;
    cin >> s;

    string nums;

    for(char c : s) {
        if(c != '+')
            nums += c;
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.length(); i++) {

        if(i > 0)
            cout << "+";

        cout << nums[i];
    }

    return 0;
}
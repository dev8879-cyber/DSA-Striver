#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> a(n);

    int sum = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(), a.end());

    int mySum = 0;
    int rem_sum = sum;
    int count = 0;

    while(mySum <= rem_sum) {

        int coin = a.back();
        a.pop_back();

        mySum += coin;
        rem_sum -= coin;

        count++;
    }

    cout << count;

    return 0;
}
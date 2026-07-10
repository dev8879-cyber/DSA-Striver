#include <iostream>
#include <vector>
using namespace std;
// Recursive: 
int rodCut(int n, vector<int>& price) {

    // Base Case
    if(n == 0)
        return 0;

    int maxi = 0;

    for(int i = 1; i <= n; i++) {
        maxi = max(maxi, price[i] + rodCut(n - i, price));
    }

    return maxi;
}

int main() {

    vector<int> price = {0,1,5,8,9,10,17,18};

    cout << rodCut(7, price);

    return 0;
}
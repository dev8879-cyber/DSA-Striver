#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maxIndex = 0;
    int minIndex = 0;

    for(int i = 0; i < n; i++) {

        // leftmost maximum
        if(a[i] > a[maxIndex]) {
            maxIndex = i;
        }

        // rightmost minimum
        if(a[i] <= a[minIndex]) {
            minIndex = i;
        }
    }

    int ans = maxIndex + (n - 1 - minIndex);

    if(minIndex < maxIndex) {
        ans--;
    }

    cout << ans;

    return 0;
}
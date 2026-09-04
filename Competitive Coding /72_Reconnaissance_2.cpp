#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int minDiff = abs(a[0] - a[1]);
    int x = 1;
    int y = 2;

    // Check normal neighbouring pairs
    for(int i = 0; i < n - 1; i++)
    {
        int diff = abs(a[i] - a[i + 1]);

        if(diff < minDiff)
        {
            minDiff = diff;
            x = i + 1;
            y = i + 2;
        }
    }

    // Check last and first soldier
    int diff = abs(a[n - 1] - a[0]);

    if(diff < minDiff)
    {
        x = n;
        y = 1;
    }

    cout << x << " " << y;

    return 0;
}
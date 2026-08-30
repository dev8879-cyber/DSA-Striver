#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if(i == 0)
            a[i] = x;
        else
            a[i] = a[i - 1] + x;
    }

    int m;
    cin >> m;

    while(m--)
    {
        int x;
        cin >> x;

        int pos = lower_bound(a, a + n, x) - a;

        cout << pos + 1 << endl;
    }

    return 0;
}
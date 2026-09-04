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
        cin >> a[i];
    }

    sort(a, a + n);

    int q;
    cin >> q;

    while(q--)
    {
        long long m;
        cin >> m;

        cout << upper_bound(a, a + n, m) - a << endl;
    }

    return 0;
}
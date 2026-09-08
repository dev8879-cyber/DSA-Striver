#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> c(m);

    int sum = 0;

    for(int i = 0; i < m; i++)
    {
        cin >> c[i];
        sum += c[i];
    }

    int water = n - sum;

    // Maximum water that can be put in all gaps
    if(water > (m + 1) * (d - 1))
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    vector<int> ans;

    for(int i = 0; i < m; i++)
    {
        // Put water before this platform
        int gap = min(water, d - 1);

        for(int j = 0; j < gap; j++)
            ans.push_back(0);

        water -= gap;

        // Put platform i+1
        for(int j = 0; j < c[i]; j++)
            ans.push_back(i + 1);
    }

    // Remaining water goes after last platform
    while(water > 0)
    {
        ans.push_back(0);
        water--;
    }

    for(int x : ans)
        cout << x << " ";

    cout << "\n";

    return 0;
}
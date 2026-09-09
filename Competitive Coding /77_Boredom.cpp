#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> freq(100001, 0);

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }

    vector<long long> dp(100001, 0);

    dp[1] = freq[1];

    for(int x = 2; x <= 100000; x++)
    {
        dp[x] = max(dp[x - 1],
                    dp[x - 2] + x * freq[x]);
    }

    cout << dp[100000] << endl;

    return 0;
}
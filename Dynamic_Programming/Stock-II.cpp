#include <iostream>
using namespace std;
// // Recursive:
// int f(int ind, int buy, vector<int>& prices)
// {
//     // Base Case
//     if(ind == prices.size())
//         return 0;

//     if(buy)
//     {
//         int take =
//             -prices[ind] + f(ind+1, 0, prices);

//         int notTake =
//             f(ind+1, 1, prices);

//         return max(take, notTake);
//     }
//     else
//     {
//         int sell =
//             prices[ind] + f(ind+1, 1, prices);

//         int notSell =
//             f(ind+1, 0, prices);

//         return max(sell, notSell);
//     }
// }

// int maxProfit(vector<int>& prices)
// {
//     return f(0, 1, prices);
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> prices(n);

//     for(int i = 0; i < n; i++)
//         cin >> prices[i];

//     cout << maxProfit(prices);
// }

// Memoization:

// int f(int ind, int buy,
//       vector<int>& prices,
//       vector<vector<int>>& dp)
// {
//     // Base Case
//     if(ind == prices.size())
//         return 0;

//     // Already Computed
//     if(dp[ind][buy] != -1)
//         return dp[ind][buy];

//     if(buy)
//     {
//         int buyStock =
//             -prices[ind] + f(ind+1, 0, prices, dp);

//         int skip =
//             f(ind+1, 1, prices, dp);

//         return dp[ind][buy] = max(buyStock, skip);
//     }
//     else
//     {
//         int sellStock =
//             prices[ind] + f(ind+1, 1, prices, dp);

//         int skip =
//             f(ind+1, 0, prices, dp);

//         return dp[ind][buy] = max(sellStock, skip);
//     }
// }

// int maxProfit(vector<int>& prices)
// {
//     int n = prices.size();

//     vector<vector<int>> dp(n, vector<int>(2, -1));

//     return f(0, 1, prices, dp);
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> prices(n);

//     for(int i = 0; i < n; i++)
//         cin >> prices[i];

//     cout << maxProfit(prices);

//     return 0;
// }

// Tabulation:

// int maxProfit(vector<int>& prices)
// {
//     int n = prices.size();

//     vector<vector<int>> dp(n + 1, vector<int>(2, 0));

//     // Fill Bottom to Top
//     for(int ind = n - 1; ind >= 0; ind--)
//     {
//         for(int buy = 0; buy <= 1; buy++)
//         {
//             if(buy)
//             {
//                 int buyStock =
//                     -prices[ind] + dp[ind + 1][0];

//                 int skip =
//                     dp[ind + 1][1];

//                 dp[ind][1] = max(buyStock, skip);
//             }
//             else
//             {
//                 int sellStock =
//                     prices[ind] + dp[ind + 1][1];

//                 int skip =
//                     dp[ind + 1][0];

//                 dp[ind][0] = max(sellStock, skip);
//             }
//         }
//     }

//     return dp[0][1];
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> prices(n);

//     for(int i = 0; i < n; i++)
//         cin >> prices[i];

//     cout << maxProfit(prices);

//     return 0;
// }

// Space Optimization:
int maxProfit(vector<int>& prices)
{
    int n = prices.size();

    vector<int> ahead(2,0);

    for(int ind=n-1; ind>=0; ind--)
    {
        vector<int> cur(2,0);

        // buy = 1
        int buyStock =
            -prices[ind] + ahead[0];

        int skipBuy =
            ahead[1];

        cur[1] = max(buyStock, skipBuy);

        // buy = 0
        int sellStock =
            prices[ind] + ahead[1];

        int skipSell =
            ahead[0];

        cur[0] = max(sellStock, skipSell);

        ahead = cur;
    }

    return ahead[1];
}

int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);

    for(int i=0;i<n;i++)
        cin >> prices[i];

    cout << maxProfit(prices);

    return 0;
}
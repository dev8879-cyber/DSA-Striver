#include<iostream>
using namespace std;
// Recrusive:
class Solution {
public:

    int f(int ind, int buy, int cap,
          vector<int>& prices)
    {
        if(ind == prices.size())
            return 0;

        if(cap == 0)
            return 0;

        if(buy)
        {
            int take =
                -prices[ind] +
                f(ind+1,0,cap,prices);

            int notTake =
                f(ind+1,1,cap,prices);

            return max(take,notTake);
        }
        else
        {
            int sell =
                prices[ind] +
                f(ind+1,1,cap-1,prices);

            int notSell =
                f(ind+1,0,cap,prices);

            return max(sell,notSell);
        }
    }

    int maxProfit(vector<int>& prices)
    {
        return f(0,1,2,prices);
    }
};
// Memoiation:
class Solution {
public:

    int f(int ind, int buy, int cap,
          vector<int>& prices,
          vector<vector<vector<int>>>& dp)
    {
        if(ind == prices.size())
            return 0;

        if(cap == 0)
            return 0;

        if(dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        if(buy)
        {
            int take = -prices[ind] +
                       f(ind+1,0,cap,prices,dp);

            int notTake =
                       f(ind+1,1,cap,prices,dp);

            return dp[ind][buy][cap] =
                   max(take,notTake);
        }
        else
        {
            int sell = prices[ind] +
                       f(ind+1,1,cap-1,prices,dp);

            int notSell =
                       f(ind+1,0,cap,prices,dp);

            return dp[ind][buy][cap] =
                   max(sell,notSell);
        }
    }

    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2,
                vector<int>(3,-1))
        );

        return f(0,1,2,prices,dp);
    }
};
// Tabulation:
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(2, vector<int>(3, 0)));

        for(int ind = n - 1; ind >= 0; ind--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int cap = 1; cap <= 2; cap++)
                {
                    if(buy)
                    {
                        int take =
                            -prices[ind] +
                            dp[ind+1][0][cap];

                        int notTake =
                            dp[ind+1][1][cap];

                        dp[ind][1][cap] =
                            max(take, notTake);
                    }
                    else
                    {
                        int sell =
                            prices[ind] +
                            dp[ind+1][1][cap-1];

                        int notSell =
                            dp[ind+1][0][cap];

                        dp[ind][0][cap] =
                            max(sell, notSell);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};

// Space Optimization:
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        vector<vector<int>> ahead(2, vector<int>(3,0));
        vector<vector<int>> cur(2, vector<int>(3,0));

        for(int ind=n-1; ind>=0; ind--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                for(int cap=1; cap<=2; cap++)
                {
                    if(buy)
                    {
                        int take =
                            -prices[ind] + ahead[0][cap];

                        int notTake =
                            ahead[1][cap];

                        cur[1][cap] =
                            max(take, notTake);
                    }
                    else
                    {
                        int sell =
                            prices[ind] + ahead[1][cap-1];

                        int notSell =
                            ahead[0][cap];

                        cur[0][cap] =
                            max(sell, notSell);
                    }
                }
            }

            ahead = cur;
        }

        return ahead[1][2];
    }
};
int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);

    for(int i = 0; i < n; i++)
        cin >> prices[i];

    Solution obj;                  // Create object of Solution class

    cout << obj.maxProfit(prices); // Call member function

    return 0;
}
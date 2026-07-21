#include<iostream>
using namespace std;
// Recursive:
class Solution {
public:

    int f(int ind, int buy,
          vector<int>& prices,
          int fee)
    {
        if(ind == prices.size())
            return 0;

        if(buy)
        {
            int take =
                -prices[ind] +
                f(ind+1,0,prices,fee);

            int notTake =
                f(ind+1,1,prices,fee);

            return max(take,notTake);
        }
        else
        {
            int sell =
                prices[ind] - fee +
                f(ind+1,1,prices,fee);

            int notSell =
                f(ind+1,0,prices,fee);

            return max(sell,notSell);
        }
    }

    int maxProfit(vector<int>& prices, int fee)
    {
        return f(0,1,prices,fee);
    }
};
// Memoiation:
class Solution {
public:

    int f(int ind, int buy,
          vector<int>& prices,
          int fee,vector<vector<int>>&dp)
    {
        if(ind == prices.size())
            return 0;

        if(buy)
        {
            int take =
                -prices[ind] +
                f(ind+1,0,prices,fee,dp);

            int notTake =
                f(ind+1,1,prices,fee,dp);

            return max(take,notTake);
        }
        else
        {
            int sell =
                prices[ind] - fee +
                f(ind+1,1,prices,fee,dp);

            int notSell =
                f(ind+1,0,prices,fee,dp);

            return dp[ind][buy]=max(sell,notSell);
        }
    }

    int maxProfit(vector<int>& prices, int fee)
    {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return f(0,1,prices,fee,dp);
    }
};
// Tabulation:
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int>(2,0));

        for(int ind=n-1; ind>=0; ind--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                if(buy)
                {
                    int take =
                        -prices[ind] + dp[ind+1][0];

                    int notTake =
                        dp[ind+1][1];

                    dp[ind][1] =
                        max(take,notTake);
                }
                else
                {
                    int sell =
                        prices[ind] - fee +
                        dp[ind+1][1];

                    int notSell =
                        dp[ind+1][0];

                    dp[ind][0] =
                        max(sell,notSell);
                }
            }
        }

        return dp[0][1];
    }
};
// Space Optimization:
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int n = prices.size();

        vector<int> ahead(2,0);
        vector<int> cur(2,0);

        for(int ind=n-1; ind>=0; ind--)
        {
            // Buy State
            cur[1] = max(
                -prices[ind] + ahead[0],
                ahead[1]
            );

            // Sell State
            cur[0] = max(
                prices[ind] - fee + ahead[1],
                ahead[0]
            );

            ahead = cur;
        }

        return ahead[1];
    }
};
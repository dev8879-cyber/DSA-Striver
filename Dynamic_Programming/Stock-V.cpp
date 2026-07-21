#include<iostream>
using namespace std;
// Recursion:
class Solution {
public:

    int f(int ind, int buy, vector<int>& prices)
    {
        if(ind >= prices.size())
            return 0;

        if(buy)
        {
            int take =
                -prices[ind] +
                f(ind+1,0,prices);

            int notTake =
                f(ind+1,1,prices);

            return max(take,notTake);
        }
        else
        {
            int sell =
                prices[ind] +
                f(ind+2,1,prices);

            int notSell =
                f(ind+1,0,prices);

            return max(sell,notSell);
        }
    }

    int maxProfit(vector<int>& prices)
    {
        return f(0,1,prices);
    }
};
// Memoiation:
class Solution {
public:

    int f(int ind, int buy,
          vector<int>& prices,
          vector<vector<int>>& dp)
    {
        if(ind >= prices.size())
            return 0;

        if(dp[ind][buy] != -1)
            return dp[ind][buy];

        if(buy)
        {
            int take =
                -prices[ind] +
                f(ind+1,0,prices,dp);

            int notTake =
                f(ind+1,1,prices,dp);

            return dp[ind][buy] =
                   max(take,notTake);
        }
        else
        {
            int sell =
                prices[ind] +
                f(ind+2,1,prices,dp);

            int notSell =
                f(ind+1,0,prices,dp);

            return dp[ind][buy] =
                   max(sell,notSell);
        }
    }

    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        vector<vector<int>> dp(
            n,
            vector<int>(2,-1)
        );

        return f(0,1,prices,dp);
    }
};
// Tabular:
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        vector<vector<int>> dp(n+2, vector<int>(2,0));

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
                        prices[ind] + dp[ind+2][1];

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
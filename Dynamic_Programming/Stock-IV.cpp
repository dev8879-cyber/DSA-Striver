#include<iostream>
using namespace std;
// Recursive:
class Solution{
public:
    int f(int ind, int buy, int cap, vector<int>& prices){
        if(ind == prices.size()) return 0;
        if(cap==0) return 0;
        if(buy){
            int take=-prices[ind]+f(ind+1,0,cap,prices);
            int not_take=+f(ind+1,1,cap,prices);
            return max(take, not_take);
        }
        else{
            int sell=prices[ind]+f(ind+1,1,cap-1,prices);
            int not_sell=+f(ind+1,0,cap,prices);
            return max(sell,not_sell);
        }
    }
    int maxProfit(vector<int>& prices,int k)
    {
        return f(0,1,k,prices);
    }

};

// Memoiattion:
class Solution{
public:
    int f(int ind, int buy, int cap, vector<int>& prices,vector<vector<vector<int>>>&dp){
        if(ind == prices.size()) return 0;
        if(cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy){
            int take=-prices[ind]+f(ind+1,0,cap,prices,dp);
            int not_take=+f(ind+1,1,cap,prices,dp);
            return dp[ind][buy][cap]=max(take, not_take);
        }
        else{
            int sell=prices[ind]+f(ind+1,1,cap-1,prices,dp);
            int not_sell=+f(ind+1,0,cap,prices,dp);
            return dp[ind][buy][cap]=max(sell,not_sell);
        }
    }
    int maxProfit(vector<int>& prices,int k)
    {
        int n=prices.size();
        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2,
                vector<int>(k+1,-1))
        );
        return f(0,1,k,prices,dp);
    }

};
// Tabulation:
class Solution{
public:
    int maxProfit(vector<int>& prices, int k){
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        vector<vector<int>> ahead(2,vector<int>(k+1,0));
        vector<vector<int>> curr(2,vector<int>(k+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<=k;cap++){
                    if(buy){
            int take=-prices[ind]+dp[ind+1][0][cap];
            int not_take=+dp[ind+1][1][cap];
            dp[ind][buy][cap]=max(take, not_take);
        }
        else{
            int sell=prices[ind]+dp[ind+1][1][cap-1];
            int not_sell=+dp[ind+1][0][cap];
            return dp[ind][buy][cap]=max(sell,not_sell);
        }
                }
            }
        }
        return dp[0][1][k];
    }
};
// Space Optimization:
class Solution {
public:
    int maxProfit( vector<int>& prices, int k)
    {
        int n = prices.size();

        vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
        vector<vector<int>> cur(2, vector<int>(k + 1, 0));

        for(int ind = n - 1; ind >= 0; ind--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int cap = 1; cap <= k; cap++)
                {
                    if(buy)
                    {
                        int take =
                            -prices[ind] + ahead[0][cap];

                        int notTake =
                            ahead[1][cap];

                        cur[1][cap] = max(take, notTake);
                    }
                    else
                    {
                        int sell =
                            prices[ind] + ahead[1][cap-1];

                        int notSell =
                            ahead[0][cap];

                        cur[0][cap] = max(sell, notSell);
                    }
                }
            }

            ahead = cur;
        }

        return ahead[1][k];
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
    int k;
    cin>>k;
    cout << obj.maxProfit(prices,k); // Call member function

    return 0;
}
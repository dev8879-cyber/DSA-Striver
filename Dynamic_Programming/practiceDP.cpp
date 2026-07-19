#include<iostream>
using namespace std;
// Recursive:
int f(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp){
    int profit=0;
    if(ind==prices.size()){
        return 0;
    }
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy){
        int take=-prices[ind]+f(ind+1,0,prices,dp);
        int not_take=f(ind+1,1,prices,dp);
        return dp[ind][buy]=max(take,not_take);
    }
    else{
        int take=prices[ind]+f(ind+1,1,prices,dp);
        int not_take=f(ind+1,0,prices,dp);
        return dp[ind][buy]=max(take,not_take);
    }
}
int maxProfit(vector<int>& prices, vector<vector<int>>& dp)
{
    return f(0, 1, prices,dp);
}

int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);

    for(int i = 0; i < n; i++)
        cin >> prices[i];

    vector<vector<int>>dp(n,vector<int>(2,-1));
    cout << maxProfit(prices,dp);
}
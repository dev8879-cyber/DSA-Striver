#include <iostream>
using namespace std;

// Recurrance:
// int frog_k(int ind,vector<int>& height, int k){
//     if(ind==0){
//         return 0;
//     }
//     int minSteps=INT_MAX;
//     for(int j=1;j<=k;j++){
//         if(ind-j > 0){
//             int jump=frog_k(ind-j,height,k)+abs(height[ind]-height[ind-j]);
//             minSteps=min(minSteps,jump);
//         }
//     }
//     return minSteps;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>height(n);
//     int k;
//     cin>>k;
//     cout<<frog_k(n,height,k);
// }

// Memoization::

// int frog_k(int ind, vector<int>&height,int k,vector<int>& dp){
//     if(ind==0){
//         return 0;
//     }
//     if(dp[ind]!=-1){
//         return dp[ind];
//     }
//     int minSteps=INT_MAX;
//     for(int j=1;j<=k;j++){
//         if(ind-j > 0){
//             int jump=frog_k(ind-j,height,k,dp)+abs(height[ind]-height[ind-j]);
//             minSteps=min(minSteps,jump);
//         }
//     }
//     return dp[ind]=minSteps;
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<int>height(n);
//     for(int elem: height){
//         cin>>elem;
//     }
//     vector<int>dp(n,-1);
//     int k;
//     cin>>k;
//     cout<<frog_k(n,height,k,dp);
// }

// Tabulation::

int frog_k(int n, vector<int> &height, int k)
{
    vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j > 0)
            {
                int jump=dp[i-j]+abs(height[i]-height[i-j]);
                minSteps = min(jump, minSteps);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n-1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int elem : height)
    {
        cin >> elem;
    }
    int k;
    cin>>k;
    cout << frog_k(n, height, k);
}

//No space can be optimised because k is not fixed. I can also reach upto N and can cause S.C.=O(k)
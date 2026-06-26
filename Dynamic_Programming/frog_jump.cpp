#include <iostream>
using namespace std;

// Recursive::
// int f(int ind, vector<int> &heights)
// {
//     if(ind == 0)
//         return 0;

//     int left = f(ind - 1, heights)
//              + abs(heights[ind] - heights[ind - 1]);

//     int right = INT_MAX;

//     if(ind > 1)
//     {
//         right = f(ind - 2, heights)
//               + abs(heights[ind] - heights[ind - 2]);
//     }

//     return min(left, right);
// }

// int frogJump(int n, vector<int> &heights)
// {
//     return f(n - 1, heights);
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> heights(n);

//     for(int i = 0; i < n; i++)
//         cin >> heights[i];

//     cout << frogJump(n, heights);
// }

// Now Passing DP Array for storing the results(Memoization):

// int frog(int ind,vector<int>& height,vector<int>& dp){
//     if(ind==0){
//         return 0;
//     }
//     if(dp[ind]!=-1){
//         return dp[ind];
//     }
//     int left=frog(ind-1,height,dp)+abs(height[ind]-height[ind-1]);
//     int right=INT_MAX;
//     if(ind>1){
//         right=frog(ind-2,height,dp)+abs(height[ind]-height[ind-2]);
//     }
//     return dp[ind]=min(left,right);
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<int>height(n);
//     for(int i=0;i<n;i++){
//         cin>>height[i];
//     }
//     vector<int>dp(n,-1);
//     cout<<frog(n,height,dp);
// }

// Tabulation(Without recursion stack)::

// int frog(int n,vector<int>&height){
//     vector<int>dp(n);
//     dp[0]=0;
//     dp[1]=dp[0]+abs(height[1]-height[0]);
//     for(int i=2;i<n;i++){
//         int left=dp[i-1]+abs(height[i]-height[i-1]);
//         int right=dp[i-1]+abs(height[i]-height[i-1]);
//         dp[i]=min(left,right);
//     }
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<int>height(n);
//     for(int i=0;i<n;i++){
//         cin>>height[i];
//     }
//     cout<<frog(n,height);
// }

// #Space optimization code::

int frog(int n,vector<int>& height){
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++){
        int left=prev+abs(height[i]-height[i-1]);
        int right=INT_MAX;
        if(i>1){
            right=prev2+abs(height[i]-height[i-2]);
        }
        int curr=min(left,right);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
int main(){
    int n;
    cin>>n;
    vector<int>height(n);
    for(int elem: height){
        cin>>elem;
    }
    cout<<frog(n,height);
}
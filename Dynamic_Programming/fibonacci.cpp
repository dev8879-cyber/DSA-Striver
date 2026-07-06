#include <iostream>
#include <vector>
using namespace std;

int main(){ //T.C.=O(N), S.C.=O(1)
    int n;
    cin>>n;
    int prev=1;
    int prev2=0;
    for(int i=2;i<=n;i++){
        int curri=prev+prev2;
        prev2=prev;
        prev=curri;
    }
    cout<<prev;
    return 0;
}
//Memoization:
// int f(int n,vector<int>& dp){
//     if(n<=1){
//         return n;
//     }
//     if(dp[n]!=-1) return dp[n];  //Step 1
//     return dp[n]=f(n-1,dp)+f(n-2,dp);  //Step 2
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<int>dp(n+1,-1); //Step 3
//     cout<<f(n,dp);
// }

//Tabulation:
// int fib(int n){

//     if(n <= 1){
//         return n;
//     }

//     vector<int> dp(n+1);

//     dp[0] = 0;
//     dp[1] = 1;

//     for(int i = 2; i <= n; i++){
//         dp[i] = dp[i-1] + dp[i-2];
//     }

//     return dp[n];
// }

// int main() {

//     int n;
//     cin >> n;

//     cout << fib(n);

//     return 0;
// }

// int f(int n)
// {
//     if(n <= 1)
//         return n;

//     return f(n-1) + f(n-2);
// }
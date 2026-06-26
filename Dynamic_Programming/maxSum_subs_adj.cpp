#include<iostream>
using namespace std;

// Recursion:
// int Sum_sub(int ind,vector<int>& arr){
//     if(ind==0){
//         return arr[0];
//     }
//     if(ind<0){
//         return 0;
//     }
//     int pick=arr[ind]+Sum_sub(ind-2);
//     int no_pick=Sum_sub(ind-1);
//     return max(pick,no_pick);
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int elem:arr){
//         cin>>elem;
//     }
//     cout<<Sum_sub(n-1,arr); //get answer at the last index.
// }

// Memoization::

// int Sum_sub(int ind, vector<int>& arr, vector<int>& dp)
// {
//     if(ind == 0)
//         return arr[0];

//     if(ind < 0)
//         return 0;

//     if(dp[ind] != -1)
//         return dp[ind];

//     int pick = arr[ind] + Sum_sub(ind-2, arr, dp);

//     int not_pick = Sum_sub(ind-1, arr, dp);

//     return dp[ind] = max(pick, not_pick);
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> arr(n);

//     for(int i=0;i<n;i++)
//         cin>>arr[i];

//     vector<int> dp(n,-1);

//     cout << Sum_sub(n-1, arr, dp);

//     return 0;
// }

// Tabulation::

int Sum_sub(int n,vector<int>arr){
    vector<int>dp(n);
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int elem: arr){
        cin>>elem;
    }
    cout<<Sum_sub(n-1,arr);
}
#include<iostream>
using namespace std;
// // Recusrsive:
// int f(int ind, int target, vector<int>& arr)
// {
//     // Base Case
//     if(ind == 0)
//     {
//         if(target == 0 && arr[0] == 0)
//             return 2;

//         if(target == 0 || target == arr[0])
//             return 1;

//         return 0;
//     }

//     // Not Take
//     int notTake = f(ind-1, target, arr);

//     // Take
//     int take = 0;

//     if(arr[ind] <= target)
//     {
//         take = f(ind-1,
//                  target-arr[ind],
//                  arr);
//     }

//     return take + notTake;
// }

// int countSubsets(vector<int>& arr, int target)
// {
//     int n = arr.size();

//     return f(n-1, target, arr);
// }

// int main()
// {
//     int n, target;
//     cin >> n >> target;

//     vector<int> arr(n);

//     for(int i = 0; i < n; i++)
//         cin >> arr[i];

//     cout << countSubsets(arr, target);

//     return 0;
// }

// // Memoiation:
// int f(int ind, int target,
//       vector<int>& arr,
//       vector<vector<int>>& dp)
// {
//     // Base Case
//     if(ind == 0)
//     {
//         if(target == 0 && arr[0] == 0)
//             return 2;

//         if(target == 0 || target == arr[0])
//             return 1;

//         return 0;
//     }

//     // DP Check
//     if(dp[ind][target] != -1)
//         return dp[ind][target];

//     // Not Take
//     int notTake = f(ind-1, target, arr, dp);

//     // Take
//     int take = 0;

//     if(arr[ind] <= target)
//     {
//         take = f(ind-1,
//                  target-arr[ind],
//                  arr,
//                  dp);
//     }

//     // Store Answer
//     return dp[ind][target] = take + notTake;
// }

// int countSubsets(vector<int>& arr, int target)
// {
//     int n = arr.size();

//     vector<vector<int>> dp(n,
//             vector<int>(target+1, -1));

//     return f(n-1, target, arr, dp);
// }

// int main()
// {
//     int n, target;
//     cin >> n >> target;

//     vector<int> arr(n);

//     for(int i=0;i<n;i++)
//         cin >> arr[i];

//     cout << countSubsets(arr, target);

//     return 0;
// }

// // Tabulation:
// int countSubsets(vector<int>& arr, int target)
// {
//     int n = arr.size();

//     vector<vector<int>> dp(n,
//             vector<int>(target+1,0));

//     // Base Cases
//     if(arr[0] == 0)
//         dp[0][0] = 2;
//     else
//         dp[0][0] = 1;

//     if(arr[0] != 0 && arr[0] <= target)
//         dp[0][arr[0]] = 1;

//     // Fill DP
//     for(int ind=1; ind<n; ind++)
//     {
//         for(int sum=0; sum<=target; sum++)
//         {
//             int notTake = dp[ind-1][sum];

//             int take = 0;

//             if(arr[ind] <= sum)
//             {
//                 take = dp[ind-1][sum-arr[ind]];
//             }

//             dp[ind][sum] = take + notTake;
//         }
//     }

//     return dp[n-1][target];
// }

// int main()
// {
//     int n,target;
//     cin>>n>>target;

//     vector<int> arr(n);

//     for(int i=0;i<n;i++)
//         cin>>arr[i];

//     cout<<countSubsets(arr,target);
// }

// Space Optimization:
int countSubsets(vector<int>& arr, int target)
{
    int n = arr.size();

    vector<int> prev(target + 1, 0);

    // Base Cases
    if(arr[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;

    if(arr[0] != 0 && arr[0] <= target)
        prev[arr[0]] = 1;

    // Fill DP
    for(int ind = 1; ind < n; ind++)
    {
        vector<int> cur(target + 1, 0);

        for(int sum = 0; sum <= target; sum++)
        {
            int notTake = prev[sum];

            int take = 0;

            if(arr[ind] <= sum)
            {
                take = prev[sum - arr[ind]];
            }

            cur[sum] = take + notTake;
        }

        prev = cur;
    }

    return prev[target];
}

int main()
{
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << countSubsets(arr, target);

    return 0;
}
#include<iostream>
using namespace std;
// Recursive:
// bool f(int ind, int target, vector<int>& arr)
// {
//     // Base Case
//     if(target == 0)
//         return true;

//     if(ind == 0)
//         return arr[0] == target;

//     // Not Take
//     bool notTake = f(ind-1, target, arr);

//     // Take
//     bool take = false;

//     if(arr[ind] <= target)
//     {
//         take = f(ind-1,
//                  target-arr[ind],
//                  arr);
//     }

//     return take || notTake;
// }

// bool subsetSumToK(int n, int k, vector<int>& arr)
// {
//     return f(n-1, k, arr);
// }

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<int> arr(n);

//     for(int i = 0; i < n; i++)
//         cin >> arr[i];

//     if(subsetSumToK(n, k, arr))
//         cout << "True";
//     else
//         cout << "False";

//     return 0;
// }

// Memoization:

// bool f(int ind, int target,
//        vector<int>& arr,
//        vector<vector<int>>& dp)
// {
//     // Base Cases
//     if(target == 0)
//         return true;

//     if(ind == 0)
//         return arr[0] == target;

//     // Already Computed
//     if(dp[ind][target] != -1)
//         return dp[ind][target];

//     // Not Take
//     bool notTake = f(ind-1, target, arr, dp);

//     // Take
//     bool take = false;

//     if(arr[ind] <= target)
//     {
//         take = f(ind-1,
//                  target-arr[ind],
//                  arr,
//                  dp);
//     }

//     return dp[ind][target] = take || notTake;
// }

// bool subsetSumToK(int n, int k, vector<int>& arr)
// {
//     vector<vector<int>> dp(n, vector<int>(k+1, -1));

//     return f(n-1, k, arr, dp);
// }

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<int> arr(n);

//     for(int i = 0; i < n; i++)
//         cin >> arr[i];

//     if(subsetSumToK(n, k, arr))
//         cout << "True";
//     else
//         cout << "False";

//     return 0;
// }

// Tabulation:

// bool subsetSumToK(int n, int k, vector<int>& arr)
// {
//     vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

//     // Base Case 1
//     for(int i = 0; i < n; i++)
//     {
//         dp[i][0] = true;
//     }

//     // Base Case 2
//     if(arr[0] <= k)
//     {
//         dp[0][arr[0]] = true;
//     }

//     // Fill Table
//     for(int ind = 1; ind < n; ind++)
//     {
//         for(int target = 1; target <= k; target++)
//         {
//             bool notTake = dp[ind-1][target];

//             bool take = false;

//             if(arr[ind] <= target)
//             {
//                 take = dp[ind-1][target-arr[ind]];
//             }

//             dp[ind][target] = take || notTake;
//         }
//     }

//     return dp[n-1][k];
// }

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<int> arr(n);

//     for(int i = 0; i < n; i++)
//         cin >> arr[i];

//     if(subsetSumToK(n, k, arr))
//         cout << "True";
//     else
//         cout << "False";

//     return 0;
// }

// Space Optimization:
bool subsetSumToK(int n, int k, vector<int>& arr)
{
    vector<bool> prev(k+1,false);

    // Base Cases
    prev[0] = true;

    if(arr[0] <= k)
        prev[arr[0]] = true;

    // Remaining Rows
    for(int ind=1; ind<n; ind++)
    {
        vector<bool> cur(k+1,false);

        cur[0] = true;

        for(int target=1; target<=k; target++)
        {
            bool notTake = prev[target];

            bool take = false;

            if(arr[ind] <= target)
            {
                take = prev[target-arr[ind]];
            }

            cur[target] = take || notTake;
        }

        prev = cur;
    }

    return prev[k];
}

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> arr(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<subsetSumToK(n,k,arr);

    return 0;
}
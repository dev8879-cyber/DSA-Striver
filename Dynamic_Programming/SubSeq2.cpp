#include<iostream>
using namespace std;
// Recursive:  
// bool f(int ind, int target, vector<int>& arr)
// {
//     // Base Cases
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

// bool canPartition(vector<int>& arr)
// {
//     int n = arr.size();

//     int totalSum = 0;

//     for(int num : arr)
//         totalSum += num;

//     // Odd sum can't be partitioned equally
//     if(totalSum % 2 != 0)
//         return false;

//     int target = totalSum / 2;

//     return f(n-1, target, arr);
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> arr(n);

//     for(int i=0;i<n;i++)
//         cin >> arr[i];

//     if(canPartition(arr))
//         cout << "True";
//     else
//         cout << "False";

//     return 0;
// }

// Memoiation:
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

// bool canPartition(vector<int>& arr)
// {
//     int n = arr.size();

//     int totalSum = 0;

//     for(int x : arr)
//         totalSum += x;

//     if(totalSum % 2 != 0)
//         return false;

//     int target = totalSum / 2;

//     vector<vector<int>> dp(
//         n,
//         vector<int>(target+1, -1)
//     );

//     return f(n-1, target, arr, dp);
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> arr(n);

//     for(int i=0;i<n;i++)
//         cin >> arr[i];

//     cout << canPartition(arr);

//     return 0;
// }

// // Tabulation:
// bool canPartition(vector<int>& arr)
// {
//     int n = arr.size();

//     int totalSum = 0;

//     for(int x : arr)
//         totalSum += x;

//     if(totalSum % 2 != 0)
//         return false;

//     int target = totalSum / 2;

//     vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

//     // Base Case
//     for(int i = 0; i < n; i++)
//     {
//         dp[i][0] = true;
//     }

//     if(arr[0] <= target)
//     {
//         dp[0][arr[0]] = true;
//     }

//     // Fill DP Table
//     for(int ind = 1; ind < n; ind++)
//     {
//         for(int sum = 1; sum <= target; sum++)
//         {
//             bool notTake = dp[ind-1][sum];

//             bool take = false;

//             if(arr[ind] <= sum)
//             {
//                 take = dp[ind-1][sum-arr[ind]];
//             }

//             dp[ind][sum] = take || notTake;
//         }
//     }

//     return dp[n-1][target];
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> arr(n);

//     for(int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     cout << canPartition(arr);

//     return 0;
// }

// Space Optimization:

bool canPartition(vector<int>& arr)
{
    int n = arr.size();

    int totalSum = 0;

    for(int x : arr)
        totalSum += x;

    // Odd sum cannot be partitioned equally
    if(totalSum % 2 != 0)
        return false;

    int target = totalSum / 2;

    vector<bool> prev(target + 1, false);

    // Base Cases
    prev[0] = true;

    if(arr[0] <= target)
        prev[arr[0]] = true;

    // Fill DP
    for(int ind = 1; ind < n; ind++)
    {
        vector<bool> cur(target + 1, false);

        cur[0] = true;

        for(int sum = 1; sum <= target; sum++)
        {
            bool notTake = prev[sum];

            bool take = false;

            if(arr[ind] <= sum)
            {
                take = prev[sum - arr[ind]];
            }

            cur[sum] = take || notTake;
        }

        prev = cur;
    }

    return prev[target];
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << canPartition(arr);

    return 0;
}
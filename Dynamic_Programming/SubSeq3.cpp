#include<iostream>
using namespace std;
// Tabulation:
// int minSubsetSumDifference(vector<int>& arr)
// {
//     int n = arr.size();

//     int totalSum = 0;

//     for(int x : arr)
//         totalSum += x;

//     vector<vector<bool>> dp(n,
//         vector<bool>(totalSum + 1, false));

//     // Base Cases
//     for(int i = 0; i < n; i++)
//         dp[i][0] = true;

//     if(arr[0] <= totalSum)
//         dp[0][arr[0]] = true;

//     // Fill DP
//     for(int ind = 1; ind < n; ind++)
//     {
//         for(int sum = 1; sum <= totalSum; sum++)
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

//     int mini = INT_MAX;

//     for(int s1 = 0; s1 <= totalSum; s1++)
//     {
//         if(dp[n-1][s1])
//         {
//             int s2 = totalSum - s1;

//             mini = min(mini, abs(s1 - s2));
//         }
//     }

//     return mini;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> arr(n);

//     for(int i = 0; i < n; i++)
//         cin >> arr[i];

//     cout << minSubsetSumDifference(arr);

//     return 0;
// }

// Space Optimization:

int minSubsetSumDifference(vector<int>& arr)
{
    int n = arr.size();

    int totalSum = 0;

    for(int x : arr)
        totalSum += x;

    vector<bool> prev(totalSum + 1, false);

    prev[0] = true;

    if(arr[0] <= totalSum)
        prev[arr[0]] = true;

    for(int ind = 1; ind < n; ind++)
    {
        vector<bool> cur(totalSum + 1, false);

        cur[0] = true;

        for(int sum = 1; sum <= totalSum; sum++)
        {
            bool notTake = prev[sum];

            bool take = false;

            if(arr[ind] <= sum)
                take = prev[sum - arr[ind]];

            cur[sum] = take || notTake;
        }

        prev = cur;
    }

    int mini = INT_MAX;

    for(int s1 = 0; s1 <= totalSum; s1++)
    {
        if(prev[s1])
        {
            int s2 = totalSum - s1;

            mini = min(mini, abs(s1 - s2));
        }
    }

    return mini;
}
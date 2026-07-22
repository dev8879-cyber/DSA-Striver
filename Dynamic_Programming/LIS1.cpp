#include <iostream>
#include <vector>
using namespace std;
// Recursive:
int f(int ind, int prev_ind, vector<int>& nums)
{
    if(ind == nums.size())
        return 0;

    int notTake = f(ind + 1, prev_ind, nums);

    int take = 0;

    if(prev_ind == -1 || nums[ind] > nums[prev_ind])
    {
        take = 1 + f(ind + 1, ind, nums);
    }

    return max(take, notTake);
}

int longestIncreasingSubsequence(vector<int>& nums)
{
    return f(0, -1, nums);
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << longestIncreasingSubsequence(nums);

    return 0;
}


// Memoization:

int f(int ind, int prev_ind,
      vector<int>& nums,
      vector<vector<int>>& dp)
{
    if(ind == nums.size())
        return 0;

    if(dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];

    int notTake = f(ind + 1, prev_ind, nums, dp);

    int take = 0;

    if(prev_ind == -1 || nums[ind] > nums[prev_ind])
    {
        take = 1 + f(ind + 1, ind, nums, dp);
    }

    return dp[ind][prev_ind + 1] = max(take, notTake);
}

int longestIncreasingSubsequence(vector<int>& nums)
{
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return f(0, -1, nums, dp);
}

int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};

    cout << longestIncreasingSubsequence(nums);

    return 0;
}
// Tabulation1:
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();

        vector<vector<int>> dp(n+1,
                               vector<int>(n+1,0));

        for(int ind=n-1; ind>=0; ind--)
        {
            for(int prev_ind=ind-1;
                prev_ind>=-1;
                prev_ind--)
            {
                int notTake =
                    dp[ind+1][prev_ind+1];

                int take = 0;

                if(prev_ind==-1 ||
                   nums[ind] > nums[prev_ind])
                {
                    take =
                    1 + dp[ind+1][ind+1];
                }

                dp[ind][prev_ind+1] =
                max(take,notTake);
            }
        }

        return dp[0][0];
    }
};
// Tabulation2:
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> dp(n,1);

        int maxi = 1;

        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev] < nums[i])
                {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};
// Printing LIS:
class Solution {
public:
    vector<int> longestIncreasingSubsequence(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> dp(n,1);
        vector<int> hash(n);

        int maxi = 1;
        int lastIndex = 0;

        for(int i=0;i<n;i++)
        {
            hash[i] = i;

            for(int prev=0; prev<i; prev++)
            {
                if(nums[prev] < nums[i] &&
                   dp[prev] + 1 > dp[i])
                {
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }

            if(dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> ans;

        ans.push_back(nums[lastIndex]);

        while(hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
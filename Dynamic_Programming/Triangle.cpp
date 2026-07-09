#include<iostream>
using namespace std;

// Recursion:
// int f(int i, int j, vector<vector<int>>& triangle)
// {
//     // Base Case
//     if(i == triangle.size() - 1)
//         return triangle[i][j];

//     int down = triangle[i][j]
//              + f(i + 1, j, triangle);

//     int diagonal = triangle[i][j]
//                  + f(i + 1, j + 1, triangle);

//     return min(down, diagonal);
// }

// int minimumTotal(vector<vector<int>>& triangle)
// {
//     return f(0, 0, triangle);
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<vector<int>> triangle(n);

//     for(int i = 0; i < n; i++)
//     {
//         triangle[i].resize(i + 1);

//         for(int j = 0; j <= i; j++)
//         {
//             cin >> triangle[i][j];
//         }
//     }

//     cout << minimumTotal(triangle);

//     return 0;
// }

// Memoization:

// int f(int i, int j,
//       vector<vector<int>>& triangle,
//       vector<vector<int>>& dp)
// {
//     // Base Case
//     if(i == triangle.size() - 1)
//         return triangle[i][j];

//     // Already Computed
//     if(dp[i][j] != -1)
//         return dp[i][j];

//     int down = triangle[i][j]
//              + f(i + 1, j, triangle, dp);

//     int diagonal = triangle[i][j]
//                  + f(i + 1, j + 1, triangle, dp);

//     return dp[i][j] = min(down, diagonal);
// }

// int minimumTotal(vector<vector<int>>& triangle)
// {
//     int n = triangle.size();

//     vector<vector<int>> dp(n, vector<int>(n, -1));

//     return f(0, 0, triangle, dp);
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<vector<int>> triangle(n);

//     for(int i = 0; i < n; i++)
//     {
//         triangle[i].resize(i + 1);

//         for(int j = 0; j <= i; j++)
//         {
//             cin >> triangle[i][j];
//         }
//     }

//     cout << minimumTotal(triangle);

//     return 0;
// }

// Tabulation:


// int minimumTotal(vector<vector<int>>& triangle)
// {
//     int n = triangle.size();

//     vector<vector<int>> dp(n, vector<int>(n,0));

//     // Base Case
//     for(int j=0; j<n; j++)
//     {
//         dp[n-1][j] = triangle[n-1][j];
//     }

//     // Fill Bottom to Top
//     for(int i=n-2; i>=0; i--)
//     {
//         for(int j=0; j<=i; j++)
//         {
//             int down = triangle[i][j] + dp[i+1][j];

//             int diagonal = triangle[i][j] + dp[i+1][j+1];

//             dp[i][j] = min(down, diagonal);
//         }
//     }

//     return dp[0][0];
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<vector<int>> triangle(n);

//     for(int i=0; i<n; i++)
//     {
//         triangle[i].resize(i+1);

//         for(int j=0; j<=i; j++)
//         {
//             cin >> triangle[i][j];
//         }
//     }

//     cout << minimumTotal(triangle);

//     return 0;
// }

// Space Optimization:

int minimumTotal(vector<vector<int>>& triangle)
{
    int n = triangle.size();

    vector<int> front(n, 0);

    // Base Case
    for(int j = 0; j < n; j++)
    {
        front[j] = triangle[n-1][j];
    }

    // Bottom to Top
    for(int i = n-2; i >= 0; i--)
    {
        vector<int> cur(n, 0);

        for(int j = 0; j <= i; j++)
        {
            int down = triangle[i][j] + front[j];

            int diagonal = triangle[i][j] + front[j+1];

            cur[j] = min(down, diagonal);
        }

        front = cur;
    }

    return front[0];
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> triangle(n);

    for(int i = 0; i < n; i++)
    {
        triangle[i].resize(i + 1);

        for(int j = 0; j <= i; j++)
        {
            cin >> triangle[i][j];
        }
    }

    cout << minimumTotal(triangle);

    return 0;
}
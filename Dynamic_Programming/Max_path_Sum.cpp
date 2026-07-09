#include <iostream>
using namespace std;
// Recursion:
// int f(int i, int j,
//       vector<vector<int>> &matrix)
// {
//     if (j < 0 || j >= matrix[0].size())
//         return -1e9;

//     if (i == 0)
//         return matrix[0][j];

//     int up = matrix[i][j] + f(i - 1, j, matrix);

//     int leftDiagonal = matrix[i][j] + f(i - 1, j - 1, matrix);

//     int rightDiagonal = matrix[i][j] + f(i - 1, j + 1, matrix);

//     return max(up,
//                max(leftDiagonal,
//                    rightDiagonal));
// }
// int getMaxPathSum(vector<vector<int>> &matrix)
// {
//     int n = matrix.size();
//     int m = matrix[0].size();

//     int maxi = -1e9;

//     for (int j = 0; j < m; j++)
//     {
//         maxi = max(maxi,
//                    f(n - 1, j, matrix));
//     }

//     return maxi;
// }
// int main()
// {
//     int m, n;
//     cin >> m >> n;

//     vector<vector<int>> matrix(m, vector<int>(n));

//     for(int i = 0; i < m; i++)
//     {
//         for(int j = 0; j < n; j++)
//         {
//             cin >> matrix[i][j];
//         }
//     }

//     cout << getMaxPathSum(matrix);

//     return 0;
// }

// Memoization:

// int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
// {
//     // Base Case
//     if (i == 0 && j == 0)
//         return grid[0][0];

//     // Outside Grid
//     if (i < 0 || j < 0)
//         return 1e9;

//     // Already Computed
//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int up = grid[i][j] + f(i - 1, j, grid, dp);

//     int left = grid[i][j] + f(i, j - 1, grid, dp);

//     return dp[i][j] = min(up, left);
// }

// int minPathSum(vector<vector<int>> &grid)
// {
//     int n = grid.size();
//     int m = grid[0].size();

//     vector<vector<int>> dp(n, vector<int>(m, -1));

//     return f(n - 1, m - 1, grid, dp);
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> grid(n, vector<int>(m));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> grid[i][j];
//         }
//     }

//     cout << minPathSum(grid);

//     return 0;
// }

// Tabulation:

// int minPathSum(vector<vector<int>>& grid)
// {
//     int n = grid.size();
//     int m = grid[0].size();

//     vector<vector<int>> dp(n, vector<int>(m, 0));

//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < m; j++)
//         {
//             if(i == 0 && j == 0)
//             {
//                 dp[i][j] = grid[i][j];
//                 continue;
//             }

//             int up = 1e9;
//             int left = 1e9;

//             if(i > 0)
//                 up = grid[i][j] + dp[i-1][j];

//             if(j > 0)
//                 left = grid[i][j] + dp[i][j-1];

//             dp[i][j] = min(up, left);
//         }
//     }

//     return dp[n-1][m-1];
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> grid(n, vector<int>(m));

//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < m; j++)
//         {
//             cin >> grid[i][j];
//         }
//     }

//     cout << minPathSum(grid);

//     return 0;
// }

// Space Optimization:

int minPathSum(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<int> prev(m,0);

    for(int i=0;i<n;i++)
    {
        vector<int> temp(m,0);

        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0)
            {
                temp[j]=grid[0][0];
                continue;
            }

            int up=1e9;
            int left=1e9;

            if(i>0)
                up=grid[i][j]+prev[j];

            if(j>0)
                left=grid[i][j]+temp[j-1];

            temp[j]=min(up,left);
        }

        prev=temp;
    }

    return prev[m-1];
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> grid(n,vector<int>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }

    cout<<minPathSum(grid);

    return 0;
}
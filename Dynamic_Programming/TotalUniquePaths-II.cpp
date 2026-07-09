#include <iostream>
using namespace std;

// Recursive:
// int f(int i, int j, vector<vector<int>>& grid)
// {
//     // Obstacle
//     if(i >= 0 && j >= 0 && grid[i][j] == 1)
//         return 0;

//     // Reached Start
//     if(i == 0 && j == 0)
//         return 1;

//     // Outside Grid
//     if(i < 0 || j < 0)
//         return 0;

//     int up = f(i - 1, j, grid);

//     int left = f(i, j - 1, grid);

//     return up + left;
// }

// int uniquePathsWithObstacles(vector<vector<int>>& grid)
// {
//     int m = grid.size();
//     int n = grid[0].size();

//     return f(m - 1, n - 1, grid);
// }

// int main()
// {
//     int m, n;
//     cin >> m >> n;

//     vector<vector<int>> grid(m, vector<int>(n));

//     for(int i = 0; i < m; i++)
//     {
//         for(int j = 0; j < n; j++)
//         {
//             cin >> grid[i][j];
//         }
//     }

//     cout << uniquePathsWithObstacles(grid);

//     return 0;
// }

// Memoization:

// int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
// {
//     if (i >= 0 && j >= 0 && grid[i][j] == 1)
//     {
//         return 0;
//     }
//     if (i == 0 && j == 0)
//         return 1;
//     if (i < 0 || j < 0)
//         return 0;
//     // Already Computed
//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int up = f(i - 1, j, grid, dp);
//     int left = f(i, j - 1, grid, dp);
//     return dp[i][j] = up + left;
// }
// int uniquePathsWithObstacles(vector<vector<int>> &grid)
// {
//     int m = grid.size();
//     int n = grid[0].size();
//     vector<vector<int>> dp(m, vector<int>(n, -1));

//     return f(m - 1, n - 1, grid, dp);
// }

// int main()
// {
//     int m, n;
//     cin >> m >> n;

//     vector<vector<int>> grid(m, vector<int>(n));

//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> grid[i][j];
//         }
//     }

//     cout << uniquePathsWithObstacles(grid);

//     return 0;
// }
// // Tabulation:

// int uniquePathsWithObstacles(vector<vector<int>> &grid)
// {
//     int m = grid.size();
//     int n = grid[0].size();
//     vector<vector<int>> dp(m, vector<int>(n, 0));
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             if(grid[i][j]==1){ //Stores '0' for obstacles
//                 dp[i][j]=0;
//                 continue;
//             }
//             if(i==0 && j==0){
//                 dp[i][j]=1;
//                 continue;
//             }
//             int up=0;
//             int left=0;
//             if(i>0){
//                 up=dp[i-1][j];
//             }
//             if(j>0){
//                 left=dp[i][j-1];
//             }
//             dp[i][j]=up+left;
//         }
//     }
//     return dp[m-1][n-1];
// }
// int main()
// {
//     int m, n;
//     cin >> m >> n;

//     vector<vector<int>> grid(m, vector<int>(n));

//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> grid[i][j];
//         }
//     }

//     cout << uniquePathsWithObstacles(grid);

//     return 0;
// }

// Space Optimization:

int uniquePathsWithObstacles(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<int> prev(n,0);

    for(int i=0;i<m;i++)
    {
        vector<int> temp(n,0);

        for(int j=0;j<n;j++)
        {
            // Obstacle
            if(grid[i][j]==1)
            {
                temp[j]=0;
                continue;
            }

            // Starting Cell
            if(i==0 && j==0)
            {
                temp[j]=1;
                continue;
            }

            int up=0;
            int left=0;

            if(i>0)
                up=prev[j];

            if(j>0)
                left=temp[j-1];

            temp[j]=up+left;
        }

        prev=temp;
    }

    return prev[n-1];
}

int main()
{
    int m,n;
    cin>>m>>n;

    vector<vector<int>> grid(m, vector<int>(n));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }

    cout<<uniquePathsWithObstacles(grid);

    return 0;
}
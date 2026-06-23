#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int row, int col,
         vector<vector<char>> &grid,
         vector<vector<int>> &vis)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    q.push({row, col});
    vis[row][col] = 1;

    // Up, Right, Down, Left
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == '1' &&
                !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
}

int main()
{
    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    cout << "Enter the grid (0/1):\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int islands = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '1')
            {
                islands++;
                bfs(i, j, grid, vis);
            }
        }
    }

    cout << "Number of Islands = " << islands << endl;

    return 0;
}
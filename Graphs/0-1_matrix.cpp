#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    cout << "Enter the matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));

    queue<pair<pair<int,int>,int>> q;

    // Push all 1's into queue
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 1)
            {
                q.push({{i,j},0});
                vis[i][j] = 1;
            }
        }
    }

    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};

    while(!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        dist[row][col] = steps;

        for(int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                q.push({{nrow,ncol},steps+1});
            }
        }
    }

    cout << "\nDistance Matrix\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
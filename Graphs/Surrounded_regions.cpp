#include <iostream>
#include <vector>
using namespace std;

void dfs(int row, int col, vector<vector<char>> &board,
         vector<vector<int>> &vis)
{
    int n = board.size();
    int m = board[0].size();

    vis[row][col] = 1;

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    for(int i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if(nrow >= 0 && nrow < n &&
           ncol >= 0 && ncol < m &&
           !vis[nrow][ncol] &&
           board[nrow][ncol] == 'O')
        {
            dfs(nrow, ncol, board, vis);
        }
    }
}

int main()
{
    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    cout << "Enter board:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));

    // First Row
    for(int j = 0; j < m; j++)
    {
        if(board[0][j] == 'O' && !vis[0][j])
            dfs(0, j, board, vis);
    }

    // Last Row
    for(int j = 0; j < m; j++)
    {
        if(board[n-1][j] == 'O' && !vis[n-1][j])
            dfs(n-1, j, board, vis);
    }

    // First Column
    for(int i = 0; i < n; i++)
    {
        if(board[i][0] == 'O' && !vis[i][0])
            dfs(i, 0, board, vis);
    }

    // Last Column
    for(int i = 0; i < n; i++)
    {
        if(board[i][m-1] == 'O' && !vis[i][m-1])
            dfs(i, m-1, board, vis);
    }

    // Convert surrounded O to X
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 'O' && !vis[i][j])
                board[i][j] = 'X';
        }
    }

    cout << "\nFinal Board:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void dfs(int row, int col,
         vector<vector<int>> &image,
         int oldColor,
         int newColor)
{
    int n = image.size();
    int m = image[0].size();

    image[row][col] = newColor;

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    for(int i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if(nrow >= 0 && nrow < n &&
           ncol >= 0 && ncol < m &&
           image[nrow][ncol] == oldColor)
        {
            dfs(nrow, ncol, image, oldColor, newColor);
        }
    }
}

int main()
{
    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> image(n, vector<int>(m));

    cout << "Enter Image:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> image[i][j];
        }
    }

    int sr, sc, newColor;

    cout << "Enter starting row and column: ";
    cin >> sr >> sc;

    cout << "Enter new color: ";
    cin >> newColor;

    int oldColor = image[sr][sc];

    // Important check
    if(oldColor != newColor)
        dfs(sr, sc, image, oldColor, newColor);

    cout << "\nUpdated Image:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
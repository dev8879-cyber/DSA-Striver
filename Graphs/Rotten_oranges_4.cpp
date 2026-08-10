#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {

    int n = grid.size();
    int m = grid[0].size();

    // { {row, col}, time }
    queue<pair<pair<int, int>, int>> q;

    int fresh = 0;

    // Put all rotten oranges into queue
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (grid[i][j] == 2) {
                q.push({{i, j}, 0});
            }
            else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int time = 0;

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    // BFS
    while (!q.empty()) {

        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;

        q.pop();

        time = max(time, t);

        // Check 4 neighbours
        for (int i = 0; i < 4; i++) {

            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == 1) {

                grid[nrow][ncol] = 2;

                fresh--;

                q.push({{nrow, ncol}, t + 1});
            }
        }
    }

    if (fresh != 0)
        return -1;

    return time;
}

int main() {

    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    cout << "Minimum time: " << orangesRotting(grid) << endl;

    return 0;
}
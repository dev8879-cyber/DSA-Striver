#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &isConnected, vector<int> &vis)
{
    vis[node] = 1;

    for (int neighbour = 0; neighbour < isConnected.size(); neighbour++)
    {
        if (isConnected[node][neighbour] == 1 && vis[neighbour] == 0)
        {
            dfs(neighbour, isConnected, vis);
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));

    cout << "Enter Adjacency Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> isConnected[i][j];
        }
    }

    vector<int> vis(n, 0);

    int provinces = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            provinces++;
            dfs(i, isConnected, vis);
        }
    }

    cout << "Number of Provinces = " << provinces << endl;

    return 0;
}
#include<iostream>
using namespace std;

int n, m;
vector<int> cat;
vector<vector<int>> adj;

int ans = 0;

void dfs(int node, int parent, int consecutiveCats)
{
    // Update consecutive cat count
    if (cat[node] == 1)
        consecutiveCats++;
    else
        consecutiveCats = 0;

    // Too many consecutive cats
    if (consecutiveCats > m)
        return;

    // If leaf, it is a restaurant
    if (node != 1 && adj[node].size() == 1)
    {
        ans++;
        return;
    }

    // Visit children
    for (int next : adj[node])
    {
        if (next != parent)
        {
            dfs(next, node, consecutiveCats);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    cat.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> cat[i];
    }

    adj.resize(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0, 0);

    cout << ans << '\n';

    return 0;
}
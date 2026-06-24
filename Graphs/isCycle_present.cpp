#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool detect(int src, vector<int> adj[], vector<int> &vis)
{
    vis[src] = 1;

    queue<pair<int, int>> q;
    q.push({src, -1});   // {node, parent}

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjacentNode : adj[node])
        {
            if (!vis[adjacentNode])
            {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            else if (adjacentNode != parent)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];

    cout << "Enter edges:\n";

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(V, 0);

    bool cycle = false;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (detect(i, adj, vis))
            {
                cycle = true;
                break;
            }
        }
    }

    if (cycle)
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}
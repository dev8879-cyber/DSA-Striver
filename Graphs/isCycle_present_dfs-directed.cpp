#include <iostream>
#include <vector>
using namespace std;

bool dfsCheck(int node, vector<int> adj[],
              vector<int> &vis,
              vector<int> &pathVis)
{
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto neighbour : adj[node])
    {
        // Not visited
        if (!vis[neighbour])
        {
            if (dfsCheck(neighbour, adj, vis, pathVis))
                return true;
        }

        // Visited and present in current DFS path
        else if (pathVis[neighbour])
        {
            return true;
        }
    }

    // Backtracking
    pathVis[node] = 0;

    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfsCheck(i, adj, vis, pathVis))
                return true;
        }
    }

    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);   // Directed Graph
    }

    if (isCycle(V, adj))
        cout << "Cycle Exists";
    else
        cout << "No Cycle";

    return 0;
}
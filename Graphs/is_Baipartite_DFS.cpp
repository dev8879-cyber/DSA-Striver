#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int col, vector<int> &color, vector<int> adj[])
{
    color[node] = col;

    for (auto neighbour : adj[node])
    {
        // If neighbour is not colored
        if (color[neighbour] == -1)
        {
            if (!dfs(neighbour, !col, color, adj))
                return false;
        }
        // If neighbour has the same color
        else if (color[neighbour] == col)
        {
            return false;
        }
    }

    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);

    // Handle disconnected graph
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, 0, color, adj))
                return false;
        }
    }

    return true;
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

        adj[u].push_back(v);
        adj[v].push_back(u);   // Undirected graph
    }

    if (isBipartite(V, adj))
        cout << "Graph is Bipartite";
    else
        cout << "Graph is NOT Bipartite";

    return 0;
}
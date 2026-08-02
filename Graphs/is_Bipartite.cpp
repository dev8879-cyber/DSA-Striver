#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check(int start, vector<int> adj[], vector<int> &color)
{
    queue<int> q;

    q.push(start);
    color[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto neighbour : adj[node])
        {
            // If neighbour is not colored
            if (color[neighbour] == -1)
            {
                color[neighbour] = !color[node];
                q.push(neighbour);
            }

            // Same color on both ends
            else if (color[neighbour] == color[node])
            {
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);

    // For disconnected graph
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!check(i, adj, color))
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
        adj[v].push_back(u);   // Remove this line if graph is directed
    }

    if (isBipartite(V, adj))
        cout << "Graph is Bipartite";
    else
        cout << "Graph is NOT Bipartite";

    return 0;
}
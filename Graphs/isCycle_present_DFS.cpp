#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent,
         vector<int> adj[],
         vector<int> &vis)
{
    vis[node] = 1;

    for(auto adjacentNode : adj[node])
    {
        if(!vis[adjacentNode])
        {
            if(dfs(adjacentNode, node, adj, vis))
                return true;
        }
        else if(adjacentNode != parent)
        {
            return true;
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

    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(V, 0);

    bool cycle = false;

    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            if(dfs(i, -1, adj, vis))
            {
                cycle = true;
                break;
            }
        }
    }

    if(cycle)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}
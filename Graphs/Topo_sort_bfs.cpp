#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);

    // Calculate indegree
    for(int i = 0; i < V; i++)
    {
        for(auto neighbour : adj[i])
        {
            indegree[neighbour]++;
        }
    }

    queue<int> q;

    // Push all nodes with indegree 0
    for(int i = 0; i < V; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for(auto neighbour : adj[node])
        {
            indegree[neighbour]--;

            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    return topo;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    vector<int> ans = topoSort(V, adj);

    cout << "Topological Order: ";

    for(auto node : ans)
        cout << node << " ";

    return 0;
}
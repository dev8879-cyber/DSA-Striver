#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Without MST:
int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // {adjacentNode, weight}
    vector<pair<int, int>> adj[V];

    cout << "Enter edges (u v wt):\n";

    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vector<int> vis(V, 0);

    // {weight, node}
    pq.push({0, 0});

    int sum = 0;

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (vis[node])
            continue;

        vis[node] = 1;
        sum += wt;

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (!vis[adjNode])
            {
                pq.push({edgeWeight, adjNode});
            }
        }
    }

    cout << "Minimum Cost = " << sum << endl;

    return 0;
}

// With MST:
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;

    vector<pair<int, int>> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
    > pq;

    vector<int> vis(V, 0);

    // {weight, node, parent}
    pq.push({0, 0, -1});

    int sum = 0;

    vector<pair<int, int>> mst;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int wt = it[0];
        int node = it[1];
        int parent = it[2];

        if (vis[node])
            continue;

        vis[node] = 1;
        sum += wt;

        if (parent != -1)
            mst.push_back({parent, node});

        for (auto neighbour : adj[node])
        {
            int adjNode = neighbour.first;
            int edgeWeight = neighbour.second;

            if (!vis[adjNode])
            {
                pq.push({edgeWeight, adjNode, node});
            }
        }
    }

    cout << "Minimum Cost = " << sum << endl;

    cout << "Edges in MST:\n";

    for (auto edge : mst)
    {
        cout << edge.first << " - " << edge.second << endl;
    }

    return 0;
}
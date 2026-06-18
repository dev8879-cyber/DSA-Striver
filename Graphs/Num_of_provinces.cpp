#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int>& vis) {

    vis[node] = 1;

    for(int neighbour : adj[node]) {

        if(vis[neighbour] == 0) {
            dfs(neighbour, adj, vis);
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> adj[n];

    for(int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n, 0);

    int provinces = 0;

    for(int i = 0; i < n; i++) {

        if(vis[i] == 0) {

            provinces++;
            dfs(i, adj, vis);
        }
    }

    cout << "Number of Provinces = "
         << provinces << endl;

    return 0;
}
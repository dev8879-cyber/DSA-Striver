#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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

    queue<int> q;

    q.push(0);
    vis[0] = 1;

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int neighbour : adj[node]) {

            if(vis[neighbour] == 0) {

                vis[neighbour] = 1;
                q.push(neighbour);
            }
        }
    }

    return 0;
}
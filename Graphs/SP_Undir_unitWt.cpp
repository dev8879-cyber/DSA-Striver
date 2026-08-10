#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {

    // Step 1: Convert edges to adjacency list
    vector<int> adj[N];

    for(auto it : edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    // Step 2: Distance array
    vector<int> dist(N, 1e9);

    // Source has distance 0
    dist[src] = 0;

    // Step 3: BFS queue
    queue<int> q;
    q.push(src);

    // Step 4: BFS
    while(!q.empty()) {

        int node = q.front();
        q.pop();

        for(auto it : adj[node]) {

            // If going through node gives shorter distance
            if(dist[node] + 1 < dist[it]) {

                dist[it] = dist[node] + 1;

                q.push(it);
            }
        }
    }

    // Step 5: Convert unreachable nodes to -1
    vector<int> ans(N, -1);

    for(int i = 0; i < N; i++) {

        if(dist[i] != 1e9) {
            ans[i] = dist[i];
        }
    }

    return ans;
}

int main() {

    int N = 9;
    int M = 10;
    int src = 0;

    vector<vector<int>> edges = {
        {0,1},
        {0,3},
        {3,4},
        {4,5},
        {5,6},
        {1,2},
        {2,6},
        {6,7},
        {7,8},
        {6,8}
    };

    vector<int> ans = shortestPath(edges, N, M, src);

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
} 
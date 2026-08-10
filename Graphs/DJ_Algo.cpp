#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;
class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {

        // min-heap: {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> dist(V, 1e9);

        // Source distance = 0
        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {

            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Traverse neighbours
            for (auto it : adj[node]) {

                int adjNode = it[0];
                int edgeWeight = it[1];

                // Relaxation
                if (dis + edgeWeight < dist[adjNode]) {

                    dist[adjNode] = dis + edgeWeight;

                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};
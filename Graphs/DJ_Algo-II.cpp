#include <iostream>
#include<set>
using namespace std;

class Solution {
public:

    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {

        set<pair<int, int>> st;

        vector<int> dist(V, 1e9);

        // {distance, node}
        st.insert({0, S});
        dist[S] = 0;

        while (!st.empty()) {

            auto it = *(st.begin());

            int dis = it.first;
            int node = it.second;

            st.erase(it);

            for (auto edge : adj[node]) {

                int adjNode = edge[0];
                int edgeWeight = edge[1];

                if (dis + edgeWeight < dist[adjNode]) {

                    // Remove old pair
                    if (dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }

                    // Update distance
                    dist[adjNode] = dis + edgeWeight;

                    // Insert new pair
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};
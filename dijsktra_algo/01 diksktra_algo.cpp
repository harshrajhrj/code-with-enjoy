#include <bits/stdc++.h>
using namespace std;

#define N 5

vector<vector<vector<int>>> createAdjList(vector<vector<int>> &edges) {
    vector<vector<vector<int>>> adj(N);

    for(const auto &edge: edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    return adj;
}

vector<int> dijkstra(vector<vector<int>> &edges, int src) {
    vector<vector<vector<int>>> adj = createAdjList(edges);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> dist(N, INT_MAX);

    pq.push({0, src}); // {dist, node}
    dist[src] = 0;

    while(!pq.empty()) {
        int u = pq.top()[1];
        pq.pop();

        for(auto n : adj[u]) {
            int v = n[0];
            int wt = n[1];

            if(dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int src = 0;
    vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 2, 8},
        {1, 4, 6},
        {2, 3, 2},
        {3, 4, 10}
    };

    vector<int> result = dijkstra(edges, src);

    for(int dist: result)
        cout << dist << " ";
}
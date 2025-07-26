#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> createAdjList(int N, vector<vector<int>> &edges)
{
    vector<vector<vector<int>>> adjList(N);
    for(auto n : edges)
    {
        adjList[n[0]].push_back({n[1], n[2]});
        adjList[n[1]].push_back({n[0], n[2]});
    }
    return adjList;
}

vector<vector<int>> createCurvedEdge(vector<vector<int>> &edges)
{
    vector<vector<int>> curvedEdge;
    for(auto n : edges)
    {
        curvedEdge.push_back({n[0], n[1], n[3]});
    }
    return curvedEdge;
}

vector<int> dijsktra_Algo(int src, int N, vector<vector<vector<int>>> &adjList)
{
    vector<int> dist(N, INT_MAX);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty())
    {
        int u = pq.top()[1];
        pq.pop();

        for(auto n : adjList[u])
        {
            int v = n[1];
            int wt = n[0];
            if(dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int findShortestPath(int a, int b, int N, int M, vector<vector<int>> &edges)
{
    vector<vector<int>> curvedEdges = createCurvedEdge(edges);
    vector<vector<vector<int>>> adjList = createAdjList(N, edges);

    vector<int> da = dijsktra_Algo(a, N, adjList);
    vector<int> db = dijsktra_Algo(b, N, adjList);

    int ans = da[b];

    for(int i = 0; i < M; i++)
    {
        int u = curvedEdges[i][0];
        int v = curvedEdges[i][1];
        int wt = curvedEdges[i][2];

        ans = min(ans, da[u] + wt + db[v]);
        ans = min(ans, da[v] + wt + db[u]);
    }

    if(ans >= 1000000001)
        return -1;
    
    return ans;
}

int main()
{
    // define edges
    // number of nodes (N)
    // number of edges (M)
    // starting point (a)
    // ending point (b)
}
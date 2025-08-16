#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    struct Edge *edge;
    struct Graph *createGraph;
};

Graph *createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[graph->E];
    return graph;
}

void findNegCycle(Graph *graph, vector<int> &vis, int src)
{
    int V = graph->V;
    int E = graph->E;

    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);

    dist[src] = 0;
    vis[src] = 0;

    bool flag = true; // it means relaxation is still happening for the |V| - 1 iterations

    // relax edges |V| - 1 times
    // V = 5, 0 1 2 3 4
    for (int i = 0; i < V - 1; i++)
    {
        if (flag == false)
            break;
        flag = false;
        for (int j = 0; j < E; j++)
        {
            // pick the edge
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                vis[v] = 1;
                dist[v] = dist[u] + weight;
                parent[v] = u;
                flag = true;
            }
        }
    }

    // Now check for the Vth iteration
    int C = -1;
    for (int j = 0; j < E; j++)
    {
        int u = graph->edge[j].src;
        int v = graph->edge[j].dest;
        int weight = graph->edge[j].weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            C = v; // this vertex is one of the negative weight cycle
            break;
        }
    }

    if (C != -1)
    {
        for (int i = 0; i < V; i++)
            C = parent[C]; // to make sure that we are reaching a cycle | covering all nodes if every node is involved in a cycle

        // To store the cycle vertex
        vector<int> cycle;
        for (int v = C;; v = parent[v])
        {

            cycle.push_back(v);
            if (v == C && cycle.size() > 1)
                break;
        }

        // Reverse cycle[]
        reverse(cycle.begin(), cycle.end());

        // Printing the negative cycle
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
        return;
    }
}

int main()
{
    int V = 8;
    int E = 8;

    struct Graph *graph = createGraph(V, E);
    vector<int> vis(V, 0);

    graph->edge[0].src = 1;
    graph->edge[0].dest = 0;
    graph->edge[0].weight = 1;

    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 2;

    graph->edge[2].src = 2;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 3;

    graph->edge[3].src = 3;
    graph->edge[3].dest = 4;
    graph->edge[3].weight = -3;

    graph->edge[4].src = 4;
    graph->edge[4].dest = 1;
    graph->edge[4].weight = -3;

    graph->edge[5].src = 5;
    graph->edge[5].dest = 6;
    graph->edge[5].weight = -1;

    graph->edge[6].src = 6;
    graph->edge[6].dest = 7;
    graph->edge[6].weight = -1;

    graph->edge[7].src = 7;
    graph->edge[7].dest = 5;
    graph->edge[7].weight = -1;

    // Run Bellman–Ford algorithm from each vertex as the source
    // and check for any negative-weight cycle
    for (int src = 0; src < V; src++)
        if (vis[src] == 0)
            findNegCycle(graph, vis, src);

    // cout << "-1\n";

    return 0;
}
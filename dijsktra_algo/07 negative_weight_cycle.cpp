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

Graph * ::createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[graph->E];
    return graph;
}

void findNegCycle(Graph* graph, vector<int> vis, int src)
{
    int V = graph->V;
    int E = graph->E;

    vector<int> dist(src, INT_MAX);
    vector<int> parent(src)
}

int main()
{
    int V = 5;
    int E = 5;

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

    // Function Call
    for (int src = 0; src < V; src++)
        if (vis[src] == 0)
            findNegCycle(graph, vis, src);
    cout << "-1\n";

    return 0;
}
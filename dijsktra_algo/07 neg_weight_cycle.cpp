#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u;
    int v;
    int wt;
};


struct Graph {
    int V, E;

    struct Edge *edge;

    struct Graph* createGraph(int V, int E);
};

struct Graph*::createGraph(int V, int E) {
    struct Graph *graph = new Graph;
    graph->V=V;
    graph->E=E;
    graph->edge=new Edge[graph->E];
    return graph;
}



int main()
{
    int V=5,E=5;
    Graph* graph = createGraph(V,E);
}
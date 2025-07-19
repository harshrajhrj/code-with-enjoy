/**
 * @file 02 topological_sort.cpp
 * Shortest Path in Directed Acyclic Graph
 */
#include <bits/stdc++.h>
using namespace std;

class AdjListNode {
    int v;
    int wt;
    public:
    AdjListNode(int _v, int _wt) {v = _v; wt = _wt;}
    int getV()  {return v;}
    int getWeight() {return wt;}
};

class Graph {
    int V;
    list<AdjListNode> *adj;

    void topologicalSortUtil(int v, vector<bool> visited[], stack<int> &stack);
    public:
    Graph(int V);

    void addEdge(int u, int v, int wt);

    void shortestPath(int s);

};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}

void Graph::addEdge(int u, int v, int wt)
{
    AdjListNode node(v, wt);
    adj[u].push_back(node);
}

void Graph::topologicalSortUtil(int v, vector<bool> visited[], stack<int> &stack)
{

}

int main() {
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int s = 1;
    cout << "Following are shortest distances from source " << s <<" n";
    g.shortestPath(s);

    return 0;
}
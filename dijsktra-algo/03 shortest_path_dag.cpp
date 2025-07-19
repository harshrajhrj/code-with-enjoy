/**
 * @file 02 topological_sort.cpp
 * Shortest Path in Directed Acyclic Graph
 */
#include <bits/stdc++.h>
using namespace std;

class AdjListNode
{
    int v;
    int wt;

public:
    AdjListNode(int _v, int _wt)
    {
        v = _v;
        wt = _wt;
    }
    int getV() { return v; }
    int getWeight() { return wt; }
};

class Graph
{
    int V;
    list<AdjListNode> *adj;

    void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &st);

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

void Graph::topologicalSortUtil(int v, vector<bool> &visited, stack<int> &st)
{
    visited[v] = true;
    list<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {
        AdjListNode node = *i;
        if (!visited[node.getV()])
        {
            topologicalSortUtil(node.getV(), visited, st);
        }
    }
    st.push(v);
}

void Graph::shortestPath(int src)
{
    stack<int> st;
    vector<bool> visited(V, false);
    vector<int> dist(V, INT_MAX);

    for (int i = 0; i < V; i++)
        if (!visited[i])
            topologicalSortUtil(i, visited, st);

    dist[src] = 0;

    while (!st.empty())
    {
        int u = st.top();
        st.pop();

        list<AdjListNode>::iterator i;
        if (dist[u] != INT_MAX)
            for (i = adj[u].begin(); i != adj[u].end(); i++)
            {
                if (dist[i->getV()] > dist[u] + i->getWeight())
                    dist[i->getV()] = dist[u] + i->getWeight();
            }
    }

    for (int i = 0; i < V; i++)
        (dist[i] == INT_MAX) ? cout << "INF " : cout << dist[i] << " ";
}

int main()
{
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
    cout << "Following are shortest distances from source " << s << " n";
    g.shortestPath(s);

    return 0;
}
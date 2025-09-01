#include <bits/stdc++.h>
using namespace std;

#define FOR(x, to) for (x = 0; x < (to); x++)
#define FORI(x, to) for (x; x < (to); x++)
#define FORR(x, arr) for (auto &x : arr)
#define ALL(a) (a.begin(), a.end())
#define mem(a, n) memset(a, n, sizeof(a))

typedef vector<int> vi;
typedef vector<vi> vii;

void addEdge(int a, int b, vii &adj)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void printParents(int node, int parent, vii &adj)
{
    if (parent == 0)
        cout << node << " Root" << endl;
    else
        cout << node << " -> " << parent << endl;

    // Using DFS to print parent of every node
    for (auto &e : adj[node])
    {
        if (e != parent)
            printParents(e, node, adj);
    }
}

void printLeafNodes(int node, vii &adj)
{
    int i = 1;
    FORI(i, adj.size())
    {
        if (adj[i].size() == 1 && i != node)
            cout << i << " ";
    }
    cout << endl;
}

void printChildren(int node, vii &adj)
{
    queue<int> q;
    vi visited(adj.size(), 0);
    q.push(node);

    // Using BFS to print all children
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        visited[u] = 1;

        for (auto &v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = 1;
                cout << u << " -> " << v;
                q.push(v);
            }
            cout << endl;
        }
    }
}

void printDegrees(int node, vii &adj)
{
    int i = 1;
    FORI(i, adj.size())
    {
        cout << i << ": ";

        // Root has no parent, thus, its degree is equal to
        // the edges it is connected to
        if (i == node)
            cout << adj[i].size() << endl;
        else
            cout << adj[i].size() - 1 << endl;
    }
}

int main()
{
    int N = 7, root = 1;
    vii adj(N + 1, vi());

    addEdge(1, 2, adj);
    addEdge(1, 3, adj);
    addEdge(1, 4, adj);
    addEdge(2, 5, adj);
    addEdge(2, 6, adj);
    addEdge(4, 7, adj);

    cout << "Print parents:" << endl;
    printParents(root, 0, adj);
    cout << "Print leaf nodes:" << endl;
    printLeafNodes(root, adj);
    cout << "Print children:" << endl;
    printChildren(root, adj);
    cout << "Print degrees:" << endl;
    printDegrees(root, adj);

    return 0;
}
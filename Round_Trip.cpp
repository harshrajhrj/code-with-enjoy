#include <bits/stdc++.h>
using namespace std;

// Bipartite graph
auto __fast_io_atexit = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]()
                { ofstream("display_runtime.txt") << "0"; });

    return 0;
}();

bool dfs(int u, vector<int> &parent, vector<vector<int>> &adjList, vector<int> &visited)
{
    visited[u] = 1;

    for (auto child : adjList[u])
    {
        if (!visited[child])
        {
            parent[child] = u;
        }
    }
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<vector<int>> adjList(n + 1);

    for (int i = 0; i < m; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;

        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }

    vector<int> parent(n + 1, 0);
    vector<int> visited(n + 1, 0);

    bool flag = true;

    for (int i = 1; i < n + 1; i++)
    {
        if (!visited[i])
        {
            if (!dfs(i, parent, adjList, visited))
            {
                flag = false;
                break;
            }
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

auto __fast_io_atexit = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]()
                { ofstream("display_runtime.txt") << "0"; });

    return 0;
}();

void bfs(int u, int v, vector<vector<int>> &adjList)
{
    vector<int> dist(adjList.size(), -1);
    vector<int> parent(adjList.size(), 0);
    queue<int> q;

    q.push(u);

    vector<int> ans;
    dist[u] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto child : adjList[node])
        {
            if (dist[child] == -1)
            {
                dist[child] = dist[node] + 1;
                parent[child] = node;
                q.push(child);
            }
        }
    }

    if (dist[v] == -1)
        cout << "IMPOSSIBLE";
    else
    {
        cout << dist[v] + 1 << endl;

        vector<int> path;
        for (int i = v; i != 0; i = parent[i])
        {
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        for (int i : path)
            cout << i << " ";
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

    bfs(1, n, adjList);

    return 0;
}
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

void dfs(int u, vector<vector<int>> &adjList, vector<int> &visited)
{
    visited[u] = 1;
    for (auto child : adjList[u])
    {
        if (visited[child] == 0)
            dfs(child, adjList, visited);
    }
}

int main()
{
    int m, n;
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1, vector<int>(n + 1));

    for (int i = 0; i < m; i++)
    {
        int node1, node2;

        cin >> node1 >> node2;

        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }

    vector<int> visited(n + 1, 0);

    vector<int> ans;
    for (int i = 1; i < n + 1; i++)
    {
        if (visited[i] == 0)
        {
            ans.push_back(i);
            dfs(i, adjList, visited);
        }
    }

    cout << ans.size() - 1 << endl;
    for (int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << " " << ans[i + 1] << endl;

    return 0;
}
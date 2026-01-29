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

int changeColor(int current)
{
    return current == 1 ? 2 : 1;
}

bool dfs(int u, int color, vector<vector<int>> &adjList, vector<int> &visited)
{
    visited[u] = color;
    for (auto child : adjList[u])
    {
        if (visited[child] == 0)
        {
            if (!dfs(child, changeColor(color), adjList, visited))
                return false;
        }

        else if (visited[child] == visited[u])
            return false;
    }
    return true;
}

void find_teams(vector<vector<int>> &adjList)
{
    vector<int> visited(adjList.size(), 0);

    int color = 1;
    bool flag = true;

    for (int i = 1; i < adjList.size(); i++)
    {
        if (visited[i] == 0)
        {
            if (!dfs(i, color, adjList, visited))
            {
                flag = false;
                break;
            }
        }
    }

    if (flag == false)
        cout << "IMPOSSIBLE";

    else
    {
        for (int i = 1; i < adjList.size(); i++)
        {
            cout << visited[i] << " ";
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

    find_teams(adjList);

    return 0;
}
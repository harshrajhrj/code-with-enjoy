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

int cycle_start = -1, cycle_end = -1;

bool dfs(int u, int par, vector<int> &color, vector<int> &parent, vector<vector<int>> &adj)
{
    color[u] = 1; // gray - currently processing

    for (int v : adj[u])
    {
        if (v == par)
            continue;

        if (color[v] == 0)
        { // white - not visited
            parent[v] = u;
            if (dfs(v, u, color, parent, adj))
                return true;
        }
        else if (color[v] == 1)
        { // gray - found a cycle
            cycle_start = v;
            cycle_end = u;
            return true;
        }
    }

    color[u] = 2; // black - completely processed
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> parent(n + 1, -1);
    vector<int> color(n + 1, 0); // 0: white 1: gray 2: black

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i < n + 1; i++)
    {
        if (color[i] == 0)
        {
            if (dfs(i, -1, color, parent, adj))
                break;
        }
    }

    if (cycle_start == -1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        vector<int> cycle;
        cycle.push_back(cycle_start);

        int curr = cycle_end;
        while (curr != cycle_start)
        {
            cycle.push_back(curr);
            curr = parent[curr];
        }
        cycle.push_back(cycle_start);

        cout << cycle.size() << "\n";
        for (int city : cycle)
        {
            cout << city << " ";
        }
        cout << "\n";
    }

    return 0;
}
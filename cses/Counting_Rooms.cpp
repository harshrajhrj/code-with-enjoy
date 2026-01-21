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

int row[] = {-1, 0, 1, 0};
int col[] = {0, -1, 0, 1};

void dfs(int u, int v, int n, int m, vector<vector<int>> &visited, vector<vector<char>> &map)
{
    visited[u][v] = 1;
    for (int k = 0; k < 4; k++)
    {
        int _u = u + row[k];
        int _v = v + col[k];

        if (_u >= 0 && _u < n && _v >= 0 && _v < m && !visited[_u][_v] && map[_u][_v] == '.')
        {
            dfs(_u, _v, n, m, visited, map);
        }
    }
}

// No. of connected components
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m));
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == '.' && !visited[i][j])
            {
                dfs(i, j, n, m, visited, map);
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}
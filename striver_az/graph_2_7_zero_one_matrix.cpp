#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

vvi solve(vvi &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    vvi visited(m, vi(n, 0));
    vvi distance(m, vi(n, 0));

    queue<pair<pi, int>> q;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j])
            {
                visited[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }

    int row[] = {-1, 0, 1, 0};
    int col[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int dis = q.front().second;
        q.pop();
        distance[i][j] = dis;

        for (int k = 0; k < 4; k++)
        {
            int ni = i + row[k];
            int nj = j + col[k];

            if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj])
            {
                visited[ni][nj] = 1;
                q.push({{ni, nj}, dis + 1});
            }
        }
    }

    return distance;
}
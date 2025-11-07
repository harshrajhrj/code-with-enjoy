#include <bits/stdc++.h>
using namespace std;

int rottenOranges(vector<vector<int>> &graph)
{
    int m = graph.size();
    int n = graph[0].size();

    queue<pair<pair<int, int>, int>> trace;

    int freshOranges = 0;

    vector<vector<int>> visited(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                // fresh oranges
                freshOranges++;
            }
            else if (graph[i][j] == 2)
            {
                trace.push({{i, j}, 0});
                visited[i][j] = 2;
            }
        }
    }

    int row[] = {-1, 0, 1, 0};
    int col[] = {0, 1, 0, -1};

    int ans = 0;

    while (!trace.empty())
    {
        int x = trace.front().first.first;
        int y = trace.front().first.second;
        int time = trace.front().second;
        trace.pop();

        ans = max(ans, time);

        for (int i = 0; i < 4; i++)
        {
            int new_row = x + row[i];
            int new_col = y + col[i];

            if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && !visited[new_row][new_col] && graph[new_row][new_col] == 1)
            {
                trace.push({{new_row, new_col}, time + 1});
                visited[new_row][new_col] = 2;
                --freshOranges;
            }
        }
    }

    return freshOranges > 0 ? -1 : ans;
}
int main()
{

    // 2 1 1
    // 1 1 0
    // 0 1 1
    vector<vector<int>> graph = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};
    cout << rottenOranges(graph);
    return 0;
}
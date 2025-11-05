#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<int>> &graph, int row[], int col[])
{
    visited[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int x = i + row[k];
        int y = j + col[k];

        if (x >= 0 && x < graph.size() && y >= 0 && y < graph[0].size() && !visited[x][y] && graph[x][y])
            dfs(x, y, visited, graph, row, col);
    }
}
int main()
{
    vector<vector<int>> graph = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}};

    int r = graph.size();
    int c = graph[0].size();

    vector<vector<int>> visited(r, vector<int>(c, 0));

    int row[] = {-1, 0, 1, 0};
    int col[] = {-0, 1, 0, -1};

    int counter = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!visited[i][j] && graph[i][j])
            {
                dfs(i, j, visited, graph, row, col);
                counter++;
            }
        }
    }

    cout << counter;

    return 0;
}
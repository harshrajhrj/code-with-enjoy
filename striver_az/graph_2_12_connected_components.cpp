#include <bits/stdc++.h>
using namespace std;

void bfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited, int row[], int col[])
{
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x][y] = 1;
        for (int i = 0; i < 8; i++)
        {
            int newRow = x + row[i];
            int newCol = y + col[i];

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol] && grid[newRow][newCol])
            {
                q.push({newRow, newCol});
            }
        }
    }
}
int connected_components(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));

    int row[] = {-1, 0, 1, 0, -1, 1, -1, 1};
    int col[] = {0, 1, 0, -1, 1, 1, -1, -1};

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] && !visited[i][j])
            {
                bfs(i, j, grid, visited, row, col);
                ans++;
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> grid = {
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 1}};

    cout << connected_components(grid);

    return 0;
}
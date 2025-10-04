#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vii visited(m, vi(n, 0));
    int countFresh = 0;
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                visited[i][j] = 2;
            }

            else if (grid[i][j] == 1)
                countFresh++;
            else
                visited[i][j] = 0;
        }

    int row[] = {-1, 0, 1, 0};
    int col[] = {0, 1, 0, -1};
    int ans = 0;
    int rotten = 0;

    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int time = q.front().second;

        ans = max(ans, time);

        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int newRow = r + row[dir];
            int newCol = c + col[dir];

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1 && visited[newRow][newCol] == 0)
            {
                visited[newRow][newCol] = 2;
                q.push({{newRow, newCol}, time + 1});
                rotten++;
            }
        }
    }

    if (rotten != countFresh)
        return -1;

    return ans;
}
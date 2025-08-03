/**
 * @file 05 min_cost_path.cpp
 * https://www.geeksforgeeks.org/dsa/minimum-cost-path-left-right-bottom-moves-allowed/
 * https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1
 */

#include <bits/stdc++.h>
using namespace std;

bool isValidCell(int i, int j, int n)
{
    return i >= 0 && i < n && j >= 0 && j < n;
}

int minimumCostPath(vector<vector<int>> &grid)
{
    int n = grid.size();

    // Min heap to implemnent dijkstra
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    // 2D grid to store minimum cost to reach every node
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    dist[0][0] = grid[0][0];

    // Direction vector to move in 4 directions
    vector<vector<int>> dirn = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    pq.push({grid[0][0], 0, 0});

    while (!pq.empty())
    {
        vector<int> top = pq.top();
        pq.pop();

        int cost = top[0];
        int i = top[1];
        int j = top[2];

        for (auto dir : dirn)
        {
            int newX = i + dir[0];
            int newY = j + dir[1];

            if (isValidCell(newX, newY, n) && dist[newX][newY] > dist[i][j] + grid[newX][newY])
            {
                dist[newX][newY] = dist[i][j] + grid[newX][newY];

                pq.push({{dist[newX][newY], newX, newY}});
            }
        }
    }
    return dist[n - 1][n - 1];
}
int main()
{
    vector<vector<int>> grid = {{9, 4, 9, 9}, {6, 7, 6, 4}, {8, 3, 3, 7}, {7, 4, 9, 10}};

    cout << minimumCostPath(grid) << endl;

    return 0;
}

/**
 * Why dynamic programming cannot be used?
 * Dynamic programming fails here because allowing movement in all four directions creates cycles where cells 
 * can be revisited, breaking the optimal substructure assumption. This means the cost to reach a cell from a 
 * given cell isn't fixed but depends on the entire path.
 */
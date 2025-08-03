#include <bits/stdc++.h>
using namespace std;

bool isValidCell(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int minAbsoluteValue(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
    cost[0][0] = 0;
    pq.push({0, 0, 0});
    vector<vector<int>> dirn = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int maxi = INT_MIN;

    while(!pq.empty())
    {
        vector<int> top = pq.top();
        pq.pop();

        int costTillNow = top[0];
        int i = top[1];
        int j = top[2];

        if (i == n - 1 && j == m - 1)
            return costTillNow;

        for(auto dir : dirn)
        {
            int newX = i + dir[0];
            int newY = j + dir[1];

            if(isValidCell(newX, newY, n, m))
            {
                int effort = max(abs(grid[newX][newY] - grid[i][j]), costTillNow);

                if(effort < cost[newX][newY])
                {
                    cost[newX][newY] = effort;
                    pq.push({effort, newX, newY});
                }
            }
        }
    }

    return -1;
}
int main()
{
    vector<vector<int>> edges = {
        { 1, 2, 2 },
        { 3, 8, 2 },
        { 5, 3, 5 }
    };

    cout << minAbsoluteValue(edges) << endl;

    edges = {
        {1, 2, 1, 1, 1},
        {1, 2, 1, 2, 1},
        {1, 2, 1, 2, 1},
        {1, 1, 1, 2, 1}
    };
    
    cout << minAbsoluteValue(edges) << endl;

    return 0;
}
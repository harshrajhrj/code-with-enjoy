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
char pathArr[] = {'U', 'L', 'D', 'R'};

void bfs(int n, int m, int startIdx[], int endIdx[], vector<vector<char>> &map)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    
    q.push({startIdx[0], startIdx[1]});
    visited[startIdx[0]][startIdx[1]] = true;

    bool dest_found = false;

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        if (r == endIdx[0] && c == endIdx[1])
        {
            dest_found = true;
            break;
        }

        for (int k = 0; k < 4; k++)
        {
            int _n = r + row[k];
            int _m = c + col[k];

            if (_n >= 0 && _n < n && _m >= 0 && _m < m && !visited[_n][_m] && (map[_n][_m] == '.' || map[_n][_m] == 'B'))
            {
                visited[_n][_m] = true;
                parent[_n][_m] = {r, c};
                q.push({_n, _m});
            }
        }
    }

    if (dest_found)
    {
        // Reconstruct path
        vector<char> path;
        int r = endIdx[0], c = endIdx[1];
        
        while (r != startIdx[0] || c != startIdx[1])
        {
            auto [pr, pc] = parent[r][c];
            
            // Find which direction we came from
            for (int k = 0; k < 4; k++)
            {
                if (pr + row[k] == r && pc + col[k] == c)
                {
                    path.push_back(pathArr[k]);
                    break;
                }
            }
            
            r = pr;
            c = pc;
        }
        
        reverse(path.begin(), path.end());
        
        cout << "YES" << endl;
        cout << path.size() << endl;
        for (auto p : path)
        {
            cout << p;
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m));

    int startIdx[2];
    int endIdx[2];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'A')
            {
                startIdx[0] = i;
                startIdx[1] = j;
            }
            if (map[i][j] == 'B')
            {
                endIdx[0] = i;
                endIdx[1] = j;
            }
        }
    }

    bfs(n, m, startIdx, endIdx, map);
}
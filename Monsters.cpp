#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    // Find starting position and monster positions
    int sx, sy;
    queue<pair<int, int>> monsters;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                sx = i;
                sy = j;
            } else if (grid[i][j] == 'M') {
                monsters.push({i, j});
            }
        }
    }
    
    // BFS to find when monsters reach each cell
    vector<vector<int>> monsterTime(n, vector<int>(m, INT_MAX));
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    string dirs = "UDLR";
    
    while (!monsters.empty()) {
        auto [x, y] = monsters.front();
        monsters.pop();
        
        if (monsterTime[x][y] != INT_MAX) continue;
        monsterTime[x][y] = 0;
        
        queue<tuple<int, int, int>> q;
        q.push({x, y, 0});
        
        while (!q.empty()) {
            auto [cx, cy, dist] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                    grid[nx][ny] != '#' && monsterTime[nx][ny] > dist + 1) {
                    monsterTime[nx][ny] = dist + 1;
                    q.push({nx, ny, dist + 1});
                }
            }
        }
    }
    
    // BFS for the person
    vector<vector<int>> personTime(n, vector<int>(m, -1));
    vector<vector<char>> parent(n, vector<char>(m, ' '));
    queue<tuple<int, int, int>> q;
    q.push({sx, sy, 0});
    personTime[sx][sy] = 0;
    
    int endX = -1, endY = -1;
    
    while (!q.empty()) {
        auto [x, y, dist] = q.front();
        q.pop();
        
        // Check if we reached boundary
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            endX = x;
            endY = y;
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                grid[nx][ny] != '#' && personTime[nx][ny] == -1) {
                
                // Person can only move if they reach before or at same time as monster
                if (dist + 1 < monsterTime[nx][ny]) {
                    personTime[nx][ny] = dist + 1;
                    parent[nx][ny] = dirs[i];
                    q.push({nx, ny, dist + 1});
                }
            }
        }
    }
    
    if (endX == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        
        // Reconstruct path
        string path;
        int x = endX, y = endY;
        
        while (x != sx || y != sy) {
            char dir = parent[x][y];
            path += dir;
            
            if (dir == 'U') x++;
            else if (dir == 'D') x--;
            else if (dir == 'L') y++;
            else if (dir == 'R') y--;
        }
        
        reverse(path.begin(), path.end());
        cout << path.length() << "\n";
        cout << path << "\n";
    }
    
    return 0;
}

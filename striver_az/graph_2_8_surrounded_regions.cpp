#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pi;

void solve(vector<vector<char>> &board)
{
    int m = board.size();
    int n = board[0].size();

    vvi visited(m, vi(n, 0));
    vvc diag(m, vc(n, 'X'));

    queue<pi> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '0')
            {
                visited[i][j] = 1;
                diag[i][j] = '0';
                q.push({i, j});
            }
        }
    }
}
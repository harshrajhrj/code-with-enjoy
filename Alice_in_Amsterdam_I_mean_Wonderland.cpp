#include <bits/stdc++.h>
using namespace std;

void solve(int n_monuments, vector<string> &name_monuments, vector<vector<long long>> &edges, int start, int dest)
{
}
int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<string> monuments(n);
        vector<vector<long long>> edges(n, vector<long long>(n));
        string str;

        for (int i = 0; i < n; i++)
        {
            cin >> monuments[i];
            for (int j = 0; j < n; j++)
                cin >> edges[i][j];
        }

        int q;
        cin >> q;
        int tc = 0;
        int start, dest;
        for (int i = 0; i < q; i++)
        {
            cin >> start;
            cin >> dest;
            cout << "Case #" << ++tc << endl;
            solve(n, monuments, edges, start, dest);
        }
    }
}
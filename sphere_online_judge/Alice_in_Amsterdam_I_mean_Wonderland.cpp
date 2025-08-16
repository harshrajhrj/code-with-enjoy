#include <bits/stdc++.h>
using namespace std;

/**
 * Floyd Warshall algorithm to find all-pairs shortest paths and negative weight cycle
 */
void solve(int n_monuments, map<string, int> &monumentIndex, vector<string> &name_monuments, vector<vector<long long>> &dist)
{
    for (int k = 0; k < n_monuments; k++)
    {
        for (int i = 0; i < n_monuments; i++)
        {
            for (int j = 0; j < n_monuments; j++)
            {
                if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Detect negative weight cycle
    vector<bool> negative_cycle(n_monuments, false);
    for (int k = 0; k < n_monuments; k++)
    {
        if (dist[k][k] < 0) // negative cycle detected
        {
            negative_cycle[k] = true;
        }
    }

    // Propagate negative cycle information
    for (int k = 0; k < n_monuments; k++)
    {
        for (int i = 0; i < n_monuments; i++)
        {
            for (int j = 0; j < n_monuments; j++)
            {
                if (dist[i][k] != LLONG_MAX && negative_cycle[k] && dist[k][j] != LLONG_MAX)
                {
                    negative_cycle[i] = true;
                }
            }
        }
    }

    int q; // queries
    cin >> q;
    int start, dest;
    for (int i = 0; i < q; i++)
    {
        cin >> start;
        cin >> dest;
        if (negative_cycle[start] || negative_cycle[dest])
        {
            cout << "NEGATIVE CYCLE" << endl;
        }
        else
        {
            cout << name_monuments[start] << "-" << name_monuments[dest] << " ";
            if (dist[start][dest] == LLONG_MAX)
            {
                cout << "NOT REACHABLE" << endl;
            }
            else
            {
                cout << dist[start][dest] << endl;
            }
        }
    }
}
int main()
{
    int tc = 0;
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;

        map<string, int> monumentIndex;
        vector<string> monuments(n);
        vector<vector<long long>> dist(n, vector<long long>(n, LLONG_MAX));
        string str;

        for (int i = 0; i < n; i++)
        {
            cin >> monuments[i];
            monumentIndex[monuments[i]] = i;
            for (int j = 0; j < n; j++)
            {
                long long d;
                cin >> d;
                if (i != j && d == 0)
                    dist[i][j] = LLONG_MAX; // No path
                else if (i == j && d > 0)
                    dist[i][j] = 0;
                else
                    dist[i][j] = d;
            }
        }
        cout << "Case #" << ++tc << ":" << endl;
        solve(n, monumentIndex, monuments, dist);
    }
}
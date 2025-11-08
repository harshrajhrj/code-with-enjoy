#include <bits/stdc++.h>
using namespace std;

double distance(int x, int y)
{
    return x * x + y * y;
}
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>> pq;

    for (auto &point : points)
    {
        double dist = distance(point[0], point[1]);
        pq.push({dist, {point[0], point[1]}});

        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    vector<vector<int>> result;

    while (!pq.empty())
    {
        result.push_back({pq.top().second.first, pq.top().second.second});
        pq.pop();
    }

    return result;
}
int main()
{
    vector<vector<int>> arr = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;

    vector<vector<int>> result = kClosest(arr, k);

    for (int i = 0; i < k; i++)
    {
        cout << result[i][0] << " " << result[i][1];
        cout << endl;
    }

    return 0;
}
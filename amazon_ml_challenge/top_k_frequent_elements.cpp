#include <bits/stdc++.h>
using namespace std;

vector<int> topKelements(vector<int> &arr, int k)
{
    unordered_map<int, int> mp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto &x : arr)
    {
        mp[x]++;
    }

    for (auto &[key, val] : mp)
    {
        pq.push({val, key});

        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    vector<int> result;
    while (!pq.empty())
    {
        auto [val, key] = pq.top();
        pq.pop();
        result.push_back(key);
    }

    return result;
}
int main()
{
    vector<int> arr = {1, 1, 1, 2, 2, 3, 3, 3};
    int k = 2;
    vector<int> result = topKelements(arr, k);
    for (int i = 0; i < k; i++)
        cout << result[i] << " ";
    return 0;
}
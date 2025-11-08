#include <bits/stdc++.h>
using namespace std;

int cost(vector<int> &arr)
{
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    int res = 0;
    while (pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int partial_cost = first + second;
        res += partial_cost;

        pq.push(partial_cost);
    }

    return res;
}
int main()
{
    vector<int> arr = {4, 3, 2, 6};
    cout << cost(arr);
    return 0;
}
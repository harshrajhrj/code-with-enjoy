#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 1, 2};
    int k = 3;
    unordered_map<int, int> mp{{0, 1}};

    int result = 0;
    int currentSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        currentSum += arr[i];
        result += mp[currentSum - k];
        mp[currentSum]++;
    }

    cout << result;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {2, 7, 8, 1};
    int target = 9;

    unordered_map<int, int> hash_map;

    for (int i = 0; i < arr.size(); i++)
    {
        hash_map[arr[i]] = i;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        int complement = target - arr[i];
        if (hash_map.find(complement) != hash_map.end())
        {
            cout << i << " " << hash_map[complement];
            break;
        }
    }

    return 0;
}
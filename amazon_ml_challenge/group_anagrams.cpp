#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> arr = {"eat", "tea", "tan", "ate", "nat", "bat"};

    unordered_map<string, vector<string>> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        string sortedstr = arr[i];
        sort(sortedstr.begin(), sortedstr.end());

        mp[sortedstr].push_back(arr[i]);
    }

    vector<vector<string>> res;

    for (auto &[key, group] : mp)
    {
        res.emplace_back(group);
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << endl << "Group " << i << ": ";
        for (auto &str : res[i])
        {
            cout << str << " ";
        }
    }

    return 0;
}
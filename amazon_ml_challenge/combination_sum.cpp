#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> combinations(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    vector<int> combinationSum;

    function<void(int, int)> backtrack = [&](int startIndex, int remainingSum)
    {
        if (remainingSum == 0)
        {
            result.push_back(combinationSum);
            return;
        }
        if (arr[startIndex] > remainingSum)
            return;

        for (int i = startIndex; i < arr.size(); i++)
        {
            combinationSum.push_back(arr[i]);
            backtrack(i, remainingSum - arr[i]);
            combinationSum.pop_back();
        }
    };

    backtrack(0, target);

    return result;
}
int main()
{
    vector<int> arr = {2, 3, 5};
    vector<vector<int>> result = combinations(arr, 8);

    for (auto &comb : result)
    {
        for (int i = 0; i < comb.size(); i++)
            cout << comb[i] << " ";

        cout << endl;
    }

    return 0;
}
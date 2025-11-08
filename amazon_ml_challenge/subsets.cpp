#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateSubsets(vector<int> &arr)
{
    vector<vector<int>> result;
    vector<int> currentSubset;

    function<void(int)> generateSubsets = [&](int index) -> void
    {
        if (index == arr.size())
        {
            result.push_back(currentSubset);
            return;
        }

        currentSubset.push_back(arr[index]); // take
        generateSubsets(index + 1);
        currentSubset.pop_back(); // do not take
        generateSubsets(index + 1);
    };
    int index = 0;
    generateSubsets(index);

    return result;
}
int main()
{
    return 0;
}
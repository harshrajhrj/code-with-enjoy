#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> permutations(vector<int> &arr)
{
    vector<vector<int>> result;
    vector<int> currentPer(arr.size());
    vector<bool> visited(arr.size(), false);

    function<void(int)> generatePermutations = [&](int index)
    {
        if (index == arr.size())
        {
            result.emplace_back(currentPer);
            return;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                currentPer[index] = arr[i]; // placing arr[i] at current position
                generatePermutations(index + 1);
                visited[i] = false;
            }
        }
    };

    generatePermutations(0);

    return result;
}
int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> result = permutations(arr);
    for (auto &per : result)
    {
        for (auto &ele : per)
            cout << ele << " ";

        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> st;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        set<int> hashmap;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(nums[i] + nums[j]);
            if (hashmap.find(third) != hashmap.end())
            {
                vector<int> triplet = {nums[i], nums[j], third};
                sort(triplet.begin(), triplet.end());
                st.insert(triplet);
            }
            hashmap.insert(nums[j]);
        }
    }
    vector<vector<int>> ans = {st.begin(), st.end()};
    return ans;
}

int main()
{
    vector<int> input = {2, -2, 0, -1, -1, 2, 0, -1, 2, -2, 0, 2, -2};
    vector<vector<int>> output = threeSum(input);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < 3; j++)
            cout << output[i][j] << " ";
        cout << endl;
    }
}
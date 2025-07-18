#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }
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
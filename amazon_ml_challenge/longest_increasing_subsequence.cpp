#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n + 1, 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i - 1])
            {
                dp[i] = max(dp[j + 1] + 1, dp[i]);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}
int main()
{
    vector<int> arr = {4, 2, 5, 3, 7};
    cout << lis(arr);
    return 0;
}
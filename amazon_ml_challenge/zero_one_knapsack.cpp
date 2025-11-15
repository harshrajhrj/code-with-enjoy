#include <bits/stdc++.h>
using namespace std;

int knapsack_value(vector<int> &weights, vector<int> &values, int max_cap)
{
    int m = weights.size();
    vector<vector<int>> dp(m + 1, vector<int>(max_cap + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= max_cap; j++)
        {
            int current_weight = weights[i - 1];
            if (j >= current_weight)
            {
                dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i][j - weights[i - 1]]);
            }
            else // if (j < weights[i - 1])
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[m][max_cap];
}
int main()
{
    vector<int> weights = {3, 4, 7};
    vector<int> values = {4, 5, 8};
    int max_weight = 7;
    cout << knapsack_value(weights, values, max_weight);
    return 0;
}
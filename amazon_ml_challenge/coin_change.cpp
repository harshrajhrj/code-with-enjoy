#include <bits/stdc++.h>
using namespace std;

int mincoins(vector<int> &coins, int target)
{
    int n = coins.size();
    vector<vector<int>> dp(coins.size() + 1, vector<int>(target + 1, INT_MAX));

    dp[0][0] = 0; // zero coins required for zero amount

    for (int index = 1; index <= n; index++)
    {
        for (int j = 0; j <= target; j++)
        {
            // do not take
            dp[index][j] = dp[index - 1][j];

            if (coins[index - 1] <= j)
            {

                dp[index][j] = min(dp[index][j], dp[index][j - coins[index - 1]] + 1);
            }
        }
    }

    return dp[n][target] > target ? -1 : dp[n][target];
}

int main()
{
    vector<int> coins = {1, 6, 5};
    int target = 11;
    cout << mincoins(coins, target);
    return 0;
}
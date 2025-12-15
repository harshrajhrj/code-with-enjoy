#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int sum(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int ans = 0;
    for (int i = 1; i <= 6; i++)
    {
        ans = (ans + sum(n - i, dp)) % MOD;
    }

    dp[n] = ans;
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << sum(n, dp);
    return 0;
}
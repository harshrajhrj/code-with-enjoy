#include <bits/stdc++.h>
using namespace std;

int lcs(string &text1, string &text2)
{
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i] == text2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
            {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[m][n];
}
int main()
{
    string text1 = "aece";
    string text2 = "ace";
    cout << lcs(text1, text2);
    return 0;
}
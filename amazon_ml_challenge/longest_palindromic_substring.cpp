#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "babad";
    int length = s.size();
    int maximum_length = 1;
    int start_index = 0;

    vector<vector<bool>> dp(length, vector<bool>(length, true));

    for (int i = length - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < length; j++)
        {
            dp[i][j] = false;

            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1];

                if (dp[i][j] && maximum_length < j - i + 1)
                {
                    maximum_length = j - i + 1;
                    start_index = i;
                }
            }
        }
    }

    cout << s.substr(start_index, maximum_length);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool wordbreak(vector<string> &wordlist, string word)
{
    set<string> wordsearch(wordlist.begin(), wordlist.end());
    int n = word.size();

    vector<bool> dp(n + 1, false);

    dp[0] = true; // empty string can always be segmented

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && wordsearch.count(word.substr(j, i - j)))
            {
                dp[i] = true;
                break; // no need to check for other splits
            }
        }
    }

    return dp[n];
}
int main()
{
    vector<string> wordlist = {"cats", "dog", "sand", "and", "cat"};
    string word = "catsandog";
    cout << wordbreak(wordlist, word);
    return 0;
}
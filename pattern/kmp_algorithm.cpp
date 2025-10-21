#include <bits/stdc++.h>
using namespace std;

void constructLPS(string &pat, vector<int> &lps)
{
    int len = 0; // length of the previous longest prefix suffix
    lps[0] = 0;
    int m = pat.size();
    int i = 1;

    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i++] = len;
        }
        else
        {
            if (len == 0)
            {
                lps[i++] = 0;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

vector<int> search(string &pat, string &text)
{
    int m = pat.size();
    int n = text.size();
    vector<int> lps(m, 0);
    constructLPS(pat, lps);
    vector<int> result;

    int i = 0, j = 0;
    while (i < n)
    {
        if (pat[j] == text[i])
        {
            j++;
            i++;
            if (j == m)
            {
                result.push_back(i - j);
                j = lps[j - 1];
            }
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return result;
}

int main()
{
    string txt = "aabaacaadaabaaba";
    string pat = "aaba";

    vector<int> res = search(pat, txt);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}
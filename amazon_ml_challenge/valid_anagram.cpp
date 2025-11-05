#include <bits/stdc++.h>
using namespace std;

bool valid_anagram(string s, string t)
{
    int slen = s.size();
    int tlen = t.size();

    if (slen != tlen)
        return 0;

    vector<int> charFreq(26, 0);

    for (int i = 0; i < slen; i++)
    {
        charFreq[s[i] - 'a']++;
        charFreq[t[i] - 'a']--;
    }

    return all_of(charFreq.begin(), charFreq.end(), [](int count)
                  { return count == 0; });
}

int main()
{
    string s = "listen";
    string t = "silent";

    cout << valid_anagram(s, t);

    return 0;
}
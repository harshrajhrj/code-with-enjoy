#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abscabsd";
    int charfreq[128] = {0};
    int longest = 0;
    int strSize = s.size();

    int j = 0;
    for (int i = 0; i < strSize; i++)
    {
        charfreq[s[i]]++;
        while (charfreq[s[i]] > 1)
        {
            charfreq[s[j]]--;
            j++;
        }

        longest = max(longest, i - j + 1);
    }
    cout << longest;
    return 0;
}
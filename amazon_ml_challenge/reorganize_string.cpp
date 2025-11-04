#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "aabaacd";

    int len = s.size();

    // count frequency
    // assumption all characters are in lowercase
    vector<int> freq(26, 0);
    for (int i = 0; i < len; i++)
    {
        freq[s[i] - 'a']++;
    }

    int maxFrequency = *max_element(freq.begin(), freq.end());
    if (maxFrequency > (len + 1) / 2)
    {
        cout << "";
        return 0;
    }

    // maintain character-freq pair
    vector<pair<int, int>> freqChar;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            freqChar.push_back({freq[i], i}); // {3, 'a'}
        }
    }

    sort(freqChar.begin(), freqChar.end());

    // start by descending
    reverse(freqChar.begin(), freqChar.end());

    string result = s;
    int i = 0;

    for (auto &fc : freqChar)
    {
        int frequency = fc.first;
        int character = fc.second;
        while (frequency--)
        {
            result[i] = 'a' + character;
            i += 2;

            if (i >= len)
                i = 1;
        }
    }

    cout << "Resulting string: ";
    for (auto &ch : result)
        cout << ch;

    return 0;
}
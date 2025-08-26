#include <iostream>
#include <string>
#include <vector>

#define FOR(x, to) for (x = 0; x < (to); x++)
#define FORI(x, to) for (x; x < (to); x++)
#define FORR(x, arr) for (auto &x : arr)
#define ALL(a) (a.begin(), a.end())
#define mem(a, n) memset(a, n, sizeof(a))

using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;
typedef vector<int> vi;

string solve(string &str)
{
    // record frequency
    vi freq(26, 0);

    string res = "";

    for (auto &s : str)
    {
        freq[s - 'A']++;
    }

    int count = 0;
    int i;

    // If more than one characters have odd frequency, then no solution exists.
    FOR(i, freq.size())
    {
        if (freq[i] % 2 & 1)
            count++;
    }

    if (count > 1)
        return "NO SOLUTION";

    string ans(str.size(), ' ');
    int left = 0;
    int right = str.size() - 1;

    FOR(i, str.size())
    {
        // Add single odd character to the middle
        if (freq[str[i] - 'A'] % 2 & 1)
        {
            ans[str.size() / 2] = str[i];
            freq[str[i] - 'A']--;
        }

        // Add the characters to the left and right to make thr string palindrome
        while (freq[str[i] - 'A'] > 0)
        {
            ans[left++] = ans[right--] = str[i];
            freq[str[i] - 'A'] -= 2;
        }
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;

    cout << solve(str);
}

// ackernman algorithm
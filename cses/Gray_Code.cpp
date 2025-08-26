#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FOR(x, to) for (x = 0; x < (to); x++)
#define FORI(x, to) for (x; x < (to); x++)
#define FORR(x, arr) for (auto &x : arr)
#define ALL(a) (a.begin(), a.end())
#define mem(a, n) memset(a, n, sizeof(a))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;

ll MOD = 1e9 + 7;

vector<string> util(int N)
{
    if (N == 1)
        return {"0", "1"};

    vector<string> smallCodes = util(N - 1);
    vector<string> newRevCodes = smallCodes;
    reverse(newRevCodes.begin(), newRevCodes.end());

    int idx = 0;
    int smc_size = smallCodes.size();
    while (idx < smc_size)
    {
        // prepend "0" in smallCode
        string _code = "0" + smallCodes[idx];

        // prepend "1" in newRevCodes
        smallCodes[idx] = "1" + newRevCodes[idx];

        smallCodes.push_back(_code);
        idx++;
    }

    return smallCodes;
}
void solve(int N)
{
    vector<string> grayCodes = util(N);
    for (auto &str : grayCodes)
    {
        cout << str << endl;
    }
}
int main()
{
    int N;
    cin >> N;
    solve(N);
}
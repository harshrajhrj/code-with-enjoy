#include <iostream>
#include <vector>
#include <string>

#define FOR(x, to) for (x = 0; x < (to); x++)
#define FORI(x, to) for (x; x < (to); x++)
#define FORR(x, arr) for (auto &x : arr)
#define ALL(a) (a.begin(), a.end())

using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;

void solve(ll base, ll N)
{
    // ll ways = 1ll << N;
    // cout << ways % MOD;
    ll ans = 1;
    while (N)
    {
        if (N & 1LL)
        {
            ans = (ans * base) % MOD;
        }
        base = (base * base) % MOD;
        N >>= 1LL;
    }
    cout << ans;
}

int main()
{
    ll N;
    cin >> N;
    solve(2ll, N);
    return 0;
}
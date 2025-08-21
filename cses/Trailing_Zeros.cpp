#include <iostream>
#include <vector>
#include <string>

#define FOR(x, to) for (x = 0; x < (to); x++)
#define FORI(x, to) for (x; x < (to); x++)
#define FORR(x, arr) for (auto &x : arr)
#define ALL(a) (a.begin(), a.end())
#define mem(a, n) memset(a, n, sizeof(a))

using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;

int solve(int N)
{
    if (N == 0)
        return 0;
    return N / 5 + solve(N / 5);
}
int main()
{
    int N;
    cin >> N;
    cout << solve(N);
    return 0;
}
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

void solve(int a, int b)
{
    // remove one coin from left pile or two coins from right pile
    // remove two coins from left pile and one coin from right pile

    // 2 1
    // 2 2
    // 3 3
    if (a == 0 && b == 0)
    {
        cout << "YES" << endl;
        return;
    }
    if (a == 0 || b == 0)
    {
        cout << "NO" << endl;
        return;
    }

    // if we want to empty first pile then we have to remove 1 coin X times from first
    // pile and 2 coins Y times from second pile
    // int A = 1 * X + 2 * Y;
    
    // Similarly to empty first pile then we have to remove 2 coins X times from first
    // pile and 1 coin Y times from second pile
    // int B = 2 * X + 1 * Y;

    // X = A - 2 * Y;
    // B = 2 * (A - 2 * Y) + 1 * Y;
    // B = 2 * A - 4 * Y + Y;
    // B = 2 * A - 3 * Y
    // Y = (2 * A - B) / 3 <========================
    // X = A - 2 * (2 * A - B) / 3
    // X = (3 * A - 4 * A + 2 * B) / 3
    // X = (2 * B - A) / 3 <========================

    if ((2 * a - b) % 3 < 0 || (2 * a - b) < 0 || (2 * b - a) % 3 || (2 * b - a) < 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    return;
}

int main()
{
    int N;
    cin >> N;
    int i;
    FOR(i, N)
    {
        int a, b;
        cin >> a >> b;
        solve(a, b);
    }
}
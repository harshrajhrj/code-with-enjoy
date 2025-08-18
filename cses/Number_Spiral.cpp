#include <bits/stdc++.h>
using namespace std;

// even column -> clockwise, odd row -> anti clockwise
// First even column = previous col + 1 .. similarly for others
// First odd row = previous row + 1 .. similarly for others

// 1  2  9  10 25
// 4  3  8  11 24
// 5  6  7  12 23
// 16 15 14 13 22
// 17 18 19 20 21
// 1 * 3 + 2 = 5
// 1 * 5 + 4

typedef long long ll;

void solve(ll x, ll y)
{
    if (x > y)
    {
        ll area = (x - 1) * (x - 1);
        ll ans = 0;
        // if row is odd, then the numbers are anti-clockwise i.e. increasing order
        if ((x & 1))
        {
            ll start = area + 1;
            ans = start + (y - 1);
        }
        // if row is even, then the numbers are clockwise i.e. decreasing order
        else
        {
            ll start = x * x;
            ans = start - (y - 1);
        }
        cout << ans << endl;
    }
    else
    {
        ll area = (y - 1) * (y - 1);
        ll ans = 0;
        if ((y & 1))
        {
            ll start = y * y;
            ans = start - (x - 1);
        }
        else
        {
            ll start = area + 1;
            ans = start + (x - 1);
        }
        cout << ans << endl;
    }
    return;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll y, x;
        cin >> y >> x;
        solve(y, x);
    }
}
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
void solve(int x, int y)
{
    int num = 1;
    if(x & 1)
    {
        for(int i = 1; i < x; i++)
        {
            
        }
    }

}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int y, x;
        cin >> y >> x;
        solve(y, x);
    }
}
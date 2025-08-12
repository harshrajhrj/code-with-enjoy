#include <bits/stdc++.h>
using namespace std;

void solve(long long n)
{
    cout<< n << " ";

    while(n != 1)
    {
        if (! (n & 1))
        {
            n = n / 2;
            cout << n << " ";
        } else {
            n = n * 3 + 1;
            cout << n << " ";
        }
    }
}
int main()
{
    // int t;
    // cin>>t;
    // while(t--)
    // {
        long long n;
        cin>>n;
        solve(n);
    // }
}
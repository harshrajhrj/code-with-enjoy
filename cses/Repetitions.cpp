#include <bits/stdc++.h>
using namespace std;


void solve(string &str)
{
    int n = str.size();
    if ( n == 1) {cout << "1"; return;}

    int ans = 1, count = 1;
    for(int i = 1; i < n; i++)
    {
        if(str[i - 1] != str[i])
        {
            count = 1;
        } else {
            count++;
        }
        ans = max(ans, count);
    }
    cout<<ans;
}


int main()
{
    string str;
    cin>>str;
    solve(str);
}
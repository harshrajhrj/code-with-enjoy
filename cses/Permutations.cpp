#include <bits/stdc++.h>
using namespace std;

void solve(int N)
{
    if (N == 1)
    {
        cout << 1 << endl;
        return;
    }
    if (N == 2 || N == 3)
    {
        cout << "NO SOLUTION" << endl;
        return;
    }

    // print all even numbers
    for (int i = 2; i <= N; i += 2)
        cout << i << " ";

    // print all odd numbers
    for (int i = 1; i <= N; i += 2)
        cout << i << " ";
}

int main()
{
    int N;
    cin >> N;
    solve(N);
}
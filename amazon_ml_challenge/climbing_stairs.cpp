#include <bits/stdc++.h>
using namespace std;

int no_of_ways(int n)
{
    int prev2 = 0;
    int prev1 = 1;
    int current = 0;

    for (int i = 0; i < n; i++)
    {
        current = prev2 + prev1;

        prev2 = prev1;   // f(i-2) becomes f(i-1)
        prev1 = current; // f(i-1) becomes f(i)
    }

    return current;
}
int main()
{
    cout << no_of_ways(20);
    return 0;
}
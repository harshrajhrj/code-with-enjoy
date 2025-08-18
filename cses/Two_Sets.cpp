#include <iostream>
#include <vector>
#include <string>

#define FOR(x, to) for (x = 0; x < (to); x++)
#define FORI(x, to) for (x; x < (to); x++)
#define FORR(x, arr) for (auto &x : arr)
#define ALL(a) (a.begin(), a.end())

using namespace std;

typedef long long ll;

void solve(int N)
{
    ll totSum = (ll)N * ((ll)N + 1) / 2;
    if (totSum & 1)
    {
        cout << "NO";
        return;
    }

    vector<int> s1;
    vector<int> s2;
    vector<int> vis(N + 1, 0);

    ll setOne = 0;
    ll maxElement = N;

    while (setOne < totSum / 2)
    {
        ll remainingSum = totSum / 2 - setOne;

        if (remainingSum > maxElement)
        {
            setOne += maxElement;
            s1.push_back(maxElement);
            vis[maxElement] = 1;
            maxElement--;
        }
        else
        {
            setOne += remainingSum;
            s1.push_back(remainingSum);
            vis[remainingSum] = 1;
        }
    }

    int i = 1;
    FORI(i, N + 1)
    {
        if (vis[i] == 0)
            s2.push_back(i);
    }
    cout << s1.size() << endl;
    FORR(x, s1)
    cout << x << " ";
    cout << endl
         << s2.size() << endl;
    FORR(x, s2)
    cout << x << " ";
    return;
}

int main()
{
    int N;
    cin >> N;
    solve(N);
}
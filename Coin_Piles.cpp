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

    // check choice one can be applied or not
    vector<int> c1 = {1, 2};
    vector<int> c2 = {2, 1};

    if((a + b) % 3 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
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
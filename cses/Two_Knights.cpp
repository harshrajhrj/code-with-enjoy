#include <iostream>
#include <vector>

#define FOR(x, to) for (x = 0; x < (to); x++)
#define FORI(x, to) for (x; x < (to); x++)
#define FORR(x, arr) for (auto &x : arr)
#define ALL(a) (a.begin(), a.end())

using namespace std;

typedef long long ll;

// number of ways two knights can be placed in nxn chess board such that they can attack each other = 4(n - 1)(n - 2)
void solve(int k)
{
    // no of squares in kxk chessboard
    ll possibleWaysforKnightOne = k * k;
    ll possibleWaysforKnightTwo = k * k - 1;

    // Possible ways for arranging two knights in a chessboard
    ll totalWays = (possibleWaysforKnightOne * possibleWaysforKnightTwo) / 2;

    // - - - -
    // - - - -
    // - - - -
    // - - - -
    // No of ways of arranging 2x3 or 3x2 blocks in kxk chessboard
    ll possibleWaysBlocks = (k - 1) * (k - 2);

    // Since in each block there are two ways in which knight can knock-out each other
    // Hence, no of ways knights can attach each other = 4 * (n - 1) * (n - 2)
    ll possibleAttacks = 4 * possibleWaysBlocks;

    cout << totalWays - possibleAttacks << endl;
}

int main()
{
    int N;
    cin >> N;
    int i = 1;
    FORI(i, N + 1)
    {
        solve(i);
    }
}
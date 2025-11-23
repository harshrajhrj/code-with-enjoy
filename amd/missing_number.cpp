#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &arr)
{
    int XORTotal = 0;
    int XORAll = 0;
    for (int i = 0; i <= arr.size(); i++)
        XORAll ^= i;
    for (int num : arr)
        XORTotal ^= num;

    return XORAll ^ XORTotal;
}
int main()
{
    vector<int> arr = {0, 1, 2, 3, 5, 6, 7, 8, 9};
    cout << missingNumber(arr);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    vector<int> res(arr.size(), 1);

    // prefix product
    for (int i = 1; i < arr.size(); i++)
    {
        res[i] = arr[i - 1] * res[i - 1];
    }

    // suffix product
    int right = 1;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        res[i] = res[i] * right;
        right = right * arr[i];
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}
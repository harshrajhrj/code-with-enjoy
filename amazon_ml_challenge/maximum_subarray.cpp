#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int maxi = INT_MIN;
    int runningsum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        runningsum += arr[i];

        if (runningsum > maxi)
        {
            maxi = runningsum;
        }

        if (runningsum < 0)
            runningsum = 0;
    }

    cout << maxi;

    return 0;
}
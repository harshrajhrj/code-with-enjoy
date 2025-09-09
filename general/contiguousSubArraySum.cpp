#include <bits/stdc++.h>
using namespace std;

int main()
{
    int global = 0;
    int sum = 0;

    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};

    for (int i = 0; i < 7; i++)
    {

        sum += arr[i];

        if (sum >= global)
            global = sum;
        else
        {
            sum = 0;
            if (arr[i] > 0)
                sum += arr[i];
        }
    }
    cout << global;

    return 0;
}
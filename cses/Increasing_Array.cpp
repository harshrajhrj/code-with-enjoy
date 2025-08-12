#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<long long>&arr)
{
    // vector<int> diff(n, 0);

    // int maxEle = *max_element(arr.begin(), arr.end());

    // for(int i = 0; i <n;i++)
    // {
    //     diff[i] = maxEle - arr[i];
    // }


    long long ans = 0;

    for(int i = 1; i<n;i++)
    {
        if(arr[i - 1] > arr[i])
        {
            ans += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }


    cout<<ans;

}

int main()
{
    int n;
    cin >> n;

    vector<long long> arr(n);

    for(int i = 0; i<n;i++)
    {
        cin>>arr[i];
    }

    solve(n, arr);
}